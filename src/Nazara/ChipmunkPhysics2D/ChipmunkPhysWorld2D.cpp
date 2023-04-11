// Copyright (C) 2023 Jérôme "Lynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - ChipmunkPhysics2D module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#include <Nazara/ChipmunkPhysics2D/ChipmunkPhysWorld2D.hpp>
#include <Nazara/ChipmunkPhysics2D/ChipmunkArbiter2D.hpp>
#include <NazaraUtils/StackArray.hpp>
#include <chipmunk/chipmunk.h>
#include <Nazara/ChipmunkPhysics2D/Debug.hpp>

namespace Nz
{
	namespace
	{
		Color CpDebugColorToColor(cpSpaceDebugColor c)
		{
			return Color{ c.r, c.g, c.b, c.a };
		}

		cpSpaceDebugColor ColorToCpDebugColor(Color c)
		{
			return cpSpaceDebugColor{ c.r, c.g, c.b, c.a };
		}

		void CpCircleCallback(cpVect pos, cpFloat angle, cpFloat radius, cpSpaceDebugColor outlineColor, cpSpaceDebugColor fillColor, cpDataPointer userdata)
		{
			auto drawOptions = static_cast<ChipmunkPhysWorld2D::DebugDrawOptions*>(userdata);
			if (drawOptions->circleCallback)
				drawOptions->circleCallback(Vector2f(float(pos.x), float(pos.y)), RadianAnglef(float(angle)), float(radius), CpDebugColorToColor(outlineColor), CpDebugColorToColor(fillColor), drawOptions->userdata);
		}

		void CpDotCallback(cpFloat size, cpVect pos, cpSpaceDebugColor color, cpDataPointer userdata)
		{
			auto drawOptions = static_cast<ChipmunkPhysWorld2D::DebugDrawOptions*>(userdata);
			if (drawOptions->dotCallback)
				drawOptions->dotCallback(Vector2f(float(pos.x), float(pos.y)), float(size), CpDebugColorToColor(color), drawOptions->userdata);
		}

		void CpPolygonCallback(int vertexCount, const cpVect* vertices, cpFloat radius, cpSpaceDebugColor outlineColor, cpSpaceDebugColor fillColor, cpDataPointer userdata)
		{
			auto drawOptions = static_cast<ChipmunkPhysWorld2D::DebugDrawOptions*>(userdata);
			if (drawOptions->polygonCallback)
			{
				//TODO: constexpr if to prevent copy/cast if sizeof(cpVect) == sizeof(Vector2f)

				StackArray<Vector2f> nVertices = NazaraStackArray(Vector2f, vertexCount);
				for (int i = 0; i < vertexCount; ++i)
					nVertices[i].Set(float(vertices[i].x), float(vertices[i].y));

				drawOptions->polygonCallback(nVertices.data(), vertexCount, float(radius), CpDebugColorToColor(outlineColor), CpDebugColorToColor(fillColor), drawOptions->userdata);
			}
		}

		void CpSegmentCallback(cpVect a, cpVect b, cpSpaceDebugColor color, cpDataPointer userdata)
		{
			auto drawOptions = static_cast<ChipmunkPhysWorld2D::DebugDrawOptions*>(userdata);
			if (drawOptions->segmentCallback)
				drawOptions->segmentCallback(Vector2f(float(a.x), float(a.y)), Vector2f(float(b.x), float(b.y)), CpDebugColorToColor(color), drawOptions->userdata);
		}

		void CpThickSegmentCallback(cpVect a, cpVect b, cpFloat radius, cpSpaceDebugColor outlineColor, cpSpaceDebugColor fillColor, cpDataPointer userdata)
		{
			auto drawOptions = static_cast<ChipmunkPhysWorld2D::DebugDrawOptions*>(userdata);
			if (drawOptions->thickSegmentCallback)
				drawOptions->thickSegmentCallback(Vector2f(float(a.x), float(a.y)), Vector2f(float(b.x), float(b.y)), float(radius), CpDebugColorToColor(outlineColor), CpDebugColorToColor(fillColor), drawOptions->userdata);
		}

		cpSpaceDebugColor CpShapeColorCallback(cpShape* shape, cpDataPointer userdata)
		{
			auto drawOptions = static_cast<ChipmunkPhysWorld2D::DebugDrawOptions*>(userdata);
			if (drawOptions->colorCallback)
			{
				ChipmunkRigidBody2D& rigidBody = *static_cast<ChipmunkRigidBody2D*>(cpShapeGetUserData(shape));
				return ColorToCpDebugColor(drawOptions->colorCallback(rigidBody, rigidBody.GetShapeIndex(shape), drawOptions->userdata));
			}
			else
				return cpSpaceDebugColor{1.f, 0.f, 0.f, 1.f};
		}
	}

	ChipmunkPhysWorld2D::ChipmunkPhysWorld2D() :
	m_maxStepCount(50),
	m_stepSize(Time::TickDuration(200)),
	m_timestepAccumulator(Time::Zero())
	{
		m_handle = cpSpaceNew();
		cpSpaceSetUserData(m_handle, this);
	}

	ChipmunkPhysWorld2D::~ChipmunkPhysWorld2D()
	{
		cpSpaceFree(m_handle);
	}

	void ChipmunkPhysWorld2D::DebugDraw(const DebugDrawOptions& options, bool drawShapes, bool drawConstraints, bool drawCollisions)
	{
		auto ColorToCpDebugColor = [](Color c) -> cpSpaceDebugColor
		{
			return cpSpaceDebugColor{ c.r, c.g, c.b, c.a };
		};

		cpSpaceDebugDrawOptions drawOptions;
		drawOptions.collisionPointColor = ColorToCpDebugColor(options.collisionPointColor);
		drawOptions.constraintColor = ColorToCpDebugColor(options.constraintColor);
		drawOptions.shapeOutlineColor = ColorToCpDebugColor(options.shapeOutlineColor);
		drawOptions.data = const_cast<DebugDrawOptions*>(&options); //< Yeah, I know, shame :bell: but it won't be used for writing anyway

		std::underlying_type_t<cpSpaceDebugDrawFlags> drawFlags = 0;
		if (drawCollisions)
			drawFlags |= CP_SPACE_DEBUG_DRAW_COLLISION_POINTS;

		if (drawConstraints)
			drawFlags |= CP_SPACE_DEBUG_DRAW_CONSTRAINTS;

		if (drawShapes)
			drawFlags |= CP_SPACE_DEBUG_DRAW_SHAPES;

		drawOptions.flags = static_cast<cpSpaceDebugDrawFlags>(drawFlags);

		// Callback trampoline
		drawOptions.colorForShape = CpShapeColorCallback;
		drawOptions.drawCircle = CpCircleCallback;
		drawOptions.drawDot = CpDotCallback;
		drawOptions.drawFatSegment = CpThickSegmentCallback;
		drawOptions.drawPolygon = CpPolygonCallback;
		drawOptions.drawSegment = CpSegmentCallback;

		cpSpaceDebugDraw(m_handle, &drawOptions);
	}

	float ChipmunkPhysWorld2D::GetDamping() const
	{
		return float(cpSpaceGetDamping(m_handle));
	}

	Vector2f ChipmunkPhysWorld2D::GetGravity() const
	{
		cpVect gravity = cpSpaceGetGravity(m_handle);
		return Vector2f(Vector2<cpFloat>(gravity.x, gravity.y));
	}

	cpSpace* ChipmunkPhysWorld2D::GetHandle() const
	{
		return m_handle;
	}

	std::size_t ChipmunkPhysWorld2D::GetIterationCount() const
	{
		return cpSpaceGetIterations(m_handle);
	}

	std::size_t ChipmunkPhysWorld2D::GetMaxStepCount() const
	{
		return m_maxStepCount;
	}

	Time ChipmunkPhysWorld2D::GetStepSize() const
	{
		return m_stepSize;
	}

	bool ChipmunkPhysWorld2D::NearestBodyQuery(const Vector2f & from, float maxDistance, UInt32 collisionGroup, UInt32 categoryMask, UInt32 collisionMask, ChipmunkRigidBody2D** nearestBody)
	{
		cpShapeFilter filter = cpShapeFilterNew(collisionGroup, categoryMask, collisionMask);

		if (cpShape* shape = cpSpacePointQueryNearest(m_handle, {from.x, from.y}, maxDistance, filter, nullptr))
		{
			if (nearestBody)
				*nearestBody = static_cast<ChipmunkRigidBody2D*>(cpShapeGetUserData(shape));

			return true;
		}
		else
			return false;
	}

	bool ChipmunkPhysWorld2D::NearestBodyQuery(const Vector2f& from, float maxDistance, UInt32 collisionGroup, UInt32 categoryMask, UInt32 collisionMask, NearestQueryResult* result)
	{
		cpShapeFilter filter = cpShapeFilterNew(collisionGroup, categoryMask, collisionMask);

		if (result)
		{
			cpPointQueryInfo queryInfo;

			if (cpSpacePointQueryNearest(m_handle, { from.x, from.y }, maxDistance, filter, &queryInfo))
			{
				result->closestPoint.Set(Vector2<cpFloat>(queryInfo.point.x, queryInfo.point.y));
				result->distance = float(queryInfo.distance);
				result->fraction.Set(Vector2<cpFloat>(queryInfo.gradient.x, queryInfo.gradient.y));
				result->nearestBody = static_cast<ChipmunkRigidBody2D*>(cpShapeGetUserData(queryInfo.shape));

				return true;
			}
			else
				return false;
		}
		else
		{
			if (cpSpacePointQueryNearest(m_handle, { from.x, from.y }, maxDistance, filter, nullptr))
				return true;
			else
				return false;
		}
	}

	void ChipmunkPhysWorld2D::RaycastQuery(const Vector2f& from, const Vector2f& to, float radius, UInt32 collisionGroup, UInt32 categoryMask, UInt32 collisionMask, const FunctionRef<void(const RaycastHit&)>& callback)
	{
		using CallbackType = std::remove_reference_t<decltype(callback)>;

		auto cpCallback = [](cpShape* shape, cpVect point, cpVect normal, cpFloat alpha, void* data)
		{
			CallbackType& callback = *static_cast<CallbackType*>(data);

			RaycastHit hitInfo;
			hitInfo.fraction = float(alpha);
			hitInfo.hitNormal.Set(Vector2<cpFloat>(normal.x, normal.y));
			hitInfo.hitPos.Set(Vector2<cpFloat>(point.x, point.y));
			hitInfo.nearestBody = static_cast<ChipmunkRigidBody2D*>(cpShapeGetUserData(shape));

			callback(hitInfo);
		};

		cpShapeFilter filter = cpShapeFilterNew(collisionGroup, categoryMask, collisionMask);
		cpSpaceSegmentQuery(m_handle, { from.x, from.y }, { to.x, to.y }, radius, filter, cpCallback, const_cast<void*>(static_cast<const void*>(&callback)));
	}

	bool ChipmunkPhysWorld2D::RaycastQuery(const Vector2f& from, const Vector2f& to, float radius, UInt32 collisionGroup, UInt32 categoryMask, UInt32 collisionMask, std::vector<RaycastHit>* hitInfos)
	{
		using ResultType = decltype(hitInfos);

		auto callback = [](cpShape* shape, cpVect point, cpVect normal, cpFloat alpha, void* data)
		{
			ResultType results = static_cast<ResultType>(data);

			RaycastHit hitInfo;
			hitInfo.fraction = float(alpha);
			hitInfo.hitNormal.Set(Vector2<cpFloat>(normal.x, normal.y));
			hitInfo.hitPos.Set(Vector2<cpFloat>(point.x, point.y));
			hitInfo.nearestBody = static_cast<ChipmunkRigidBody2D*>(cpShapeGetUserData(shape));

			results->emplace_back(std::move(hitInfo));
		};

		cpShapeFilter filter = cpShapeFilterNew(collisionGroup, categoryMask, collisionMask);

		std::size_t previousSize = hitInfos->size();
		cpSpaceSegmentQuery(m_handle, { from.x, from.y }, { to.x, to.y }, radius, filter, callback, hitInfos);

		return hitInfos->size() != previousSize;
	}

	bool ChipmunkPhysWorld2D::RaycastQueryFirst(const Vector2f& from, const Vector2f& to, float radius, UInt32 collisionGroup, UInt32 categoryMask, UInt32 collisionMask, RaycastHit* hitInfo)
	{
		cpShapeFilter filter = cpShapeFilterNew(collisionGroup, categoryMask, collisionMask);

		if (hitInfo)
		{
			cpSegmentQueryInfo queryInfo;

			if (cpSpaceSegmentQueryFirst(m_handle, { from.x, from.y }, { to.x, to.y }, radius, filter, &queryInfo))
			{
				hitInfo->fraction = float(queryInfo.alpha);
				hitInfo->hitNormal.Set(Vector2<cpFloat>(queryInfo.normal.x, queryInfo.normal.y));
				hitInfo->hitPos.Set(Vector2<cpFloat>(queryInfo.point.x, queryInfo.point.y));
				hitInfo->nearestBody = static_cast<ChipmunkRigidBody2D*>(cpShapeGetUserData(queryInfo.shape));

				return true;
			}
			else
				return false;
		}
		else
		{
			if (cpSpaceSegmentQueryFirst(m_handle, { from.x, from.y }, { to.x, to.y }, radius, filter, nullptr))
				return true;
			else
				return false;
		}
	}

	void ChipmunkPhysWorld2D::RegionQuery(const Rectf& boundingBox, UInt32 collisionGroup, UInt32 categoryMask, UInt32 collisionMask, const FunctionRef<void(ChipmunkRigidBody2D*)>& callback)
	{
		using CallbackType = std::remove_reference_t<decltype(callback)>;

		auto cpCallback = [](cpShape* shape, void* data)
		{
			CallbackType& callback = *static_cast<CallbackType*>(data);
			callback(static_cast<ChipmunkRigidBody2D*>(cpShapeGetUserData(shape)));
		};

		cpShapeFilter filter = cpShapeFilterNew(collisionGroup, categoryMask, collisionMask);
		cpSpaceBBQuery(m_handle, cpBBNew(boundingBox.x, boundingBox.y, boundingBox.x + boundingBox.width, boundingBox.y + boundingBox.height), filter, cpCallback, const_cast<void*>(static_cast<const void*>(&callback)));
	}

	void ChipmunkPhysWorld2D::RegionQuery(const Rectf& boundingBox, UInt32 collisionGroup, UInt32 categoryMask, UInt32 collisionMask, std::vector<ChipmunkRigidBody2D*>* bodies)
	{
		using ResultType = decltype(bodies);

		auto callback = [] (cpShape* shape, void* data)
		{
			ResultType results = static_cast<ResultType>(data);
			results->push_back(static_cast<ChipmunkRigidBody2D*>(cpShapeGetUserData(shape)));
		};

		cpShapeFilter filter = cpShapeFilterNew(collisionGroup, categoryMask, collisionMask);
		cpSpaceBBQuery(m_handle, cpBBNew(boundingBox.x, boundingBox.y, boundingBox.x + boundingBox.width, boundingBox.y + boundingBox.height), filter, callback, bodies);
	}

	void ChipmunkPhysWorld2D::RegisterCallbacks(unsigned int collisionId, Callback callbacks)
	{
		InitCallbacks(cpSpaceAddWildcardHandler(m_handle, collisionId), std::move(callbacks));
	}

	void ChipmunkPhysWorld2D::RegisterCallbacks(unsigned int collisionIdA, unsigned int collisionIdB, Callback callbacks)
	{
		InitCallbacks(cpSpaceAddCollisionHandler(m_handle, collisionIdA, collisionIdB), std::move(callbacks));
	}

	void ChipmunkPhysWorld2D::SetDamping(float dampingValue)
	{
		cpSpaceSetDamping(m_handle, dampingValue);
	}

	void ChipmunkPhysWorld2D::SetGravity(const Vector2f& gravity)
	{
		cpSpaceSetGravity(m_handle, cpv(gravity.x, gravity.y));
	}

	void ChipmunkPhysWorld2D::SetIterationCount(std::size_t iterationCount)
	{
		cpSpaceSetIterations(m_handle, SafeCast<int>(iterationCount));
	}

	void ChipmunkPhysWorld2D::SetMaxStepCount(std::size_t maxStepCount)
	{
		m_maxStepCount = maxStepCount;
	}

	void ChipmunkPhysWorld2D::SetSleepTime(Time sleepTime)
	{
		if (sleepTime > Time::Zero())
			cpSpaceSetSleepTimeThreshold(m_handle, sleepTime.AsSeconds<cpFloat>());
		else
			cpSpaceSetSleepTimeThreshold(m_handle, std::numeric_limits<cpFloat>::infinity());
	}

	void ChipmunkPhysWorld2D::SetStepSize(Time stepSize)
	{
		m_stepSize = stepSize;
	}

	void ChipmunkPhysWorld2D::Step(Time timestep)
	{
		m_timestepAccumulator += timestep;

		std::size_t stepCount = std::min(static_cast<std::size_t>(static_cast<Int64>(m_timestepAccumulator / m_stepSize)), m_maxStepCount);
		float invStepCount = 1.f / stepCount;

		cpFloat dt = m_stepSize.AsSeconds<float>(); //< FIXME: AsSeconds<cpFloat> is more precise but it fails unit tests on Linux
		for (std::size_t i = 0; i < stepCount; ++i)
		{
			OnPhysWorld2DPreStep(this, invStepCount);

			cpSpaceStep(m_handle, dt);

			OnPhysWorld2DPostStep(this, invStepCount);
			if (!m_rigidPostSteps.empty())
			{
				for (const auto& pair : m_rigidPostSteps)
				{
					for (const auto& step : pair.second.funcs)
						step(pair.first);
				}

				m_rigidPostSteps.clear();
			}

			m_timestepAccumulator -= m_stepSize;
		}
	}

	void ChipmunkPhysWorld2D::UseSpatialHash(float cellSize, std::size_t entityCount)
	{
		cpSpaceUseSpatialHash(m_handle, cpFloat(cellSize), int(entityCount));
	}

	void ChipmunkPhysWorld2D::InitCallbacks(cpCollisionHandler* handler, Callback callbacks)
	{
		auto it = m_callbacks.find(handler);
		if (it == m_callbacks.end())
			it = m_callbacks.emplace(handler, std::make_unique<Callback>(std::move(callbacks))).first;
		else
			it->second = std::make_unique<Callback>(std::move(callbacks));

		Callback* callbackFunctions = it->second.get();
		handler->userData = callbackFunctions;

		if (callbackFunctions->startCallback)
		{
			handler->beginFunc = [](cpArbiter* arb, cpSpace* space, void* data) -> cpBool
			{
				cpBody* firstBody;
				cpBody* secondBody;
				cpArbiterGetBodies(arb, &firstBody, &secondBody);

				ChipmunkPhysWorld2D* world = static_cast<ChipmunkPhysWorld2D*>(cpSpaceGetUserData(space));
				ChipmunkRigidBody2D* firstRigidBody = static_cast<ChipmunkRigidBody2D*>(cpBodyGetUserData(firstBody));
				ChipmunkRigidBody2D* secondRigidBody = static_cast<ChipmunkRigidBody2D*>(cpBodyGetUserData(secondBody));

				ChipmunkArbiter2D arbiter(arb);

				const Callback* customCallbacks = static_cast<const Callback*>(data);
				if (customCallbacks->startCallback(*world, arbiter, *firstRigidBody, *secondRigidBody, customCallbacks->userdata))
					return cpTrue;
				else
					return cpFalse;
			};
		}
		else
		{
			handler->beginFunc = [](cpArbiter*, cpSpace*, void*) -> cpBool
			{
				return cpTrue;
			};
		}

		if (callbackFunctions->endCallback)
		{
			handler->separateFunc = [](cpArbiter* arb, cpSpace* space, void* data)
			{
				cpBody* firstBody;
				cpBody* secondBody;
				cpArbiterGetBodies(arb, &firstBody, &secondBody);

				ChipmunkPhysWorld2D* world = static_cast<ChipmunkPhysWorld2D*>(cpSpaceGetUserData(space));
				ChipmunkRigidBody2D* firstRigidBody = static_cast<ChipmunkRigidBody2D*>(cpBodyGetUserData(firstBody));
				ChipmunkRigidBody2D* secondRigidBody = static_cast<ChipmunkRigidBody2D*>(cpBodyGetUserData(secondBody));

				ChipmunkArbiter2D arbiter(arb);

				const Callback* customCallbacks = static_cast<const Callback*>(data);
				customCallbacks->endCallback(*world, arbiter, *firstRigidBody, *secondRigidBody, customCallbacks->userdata);
			};
		}
		else
		{
			handler->separateFunc = [](cpArbiter*, cpSpace*, void*)
			{
			};
		}

		if (callbackFunctions->preSolveCallback)
		{
			handler->preSolveFunc = [](cpArbiter* arb, cpSpace* space, void* data) -> cpBool
			{
				cpBody* firstBody;
				cpBody* secondBody;
				cpArbiterGetBodies(arb, &firstBody, &secondBody);

				ChipmunkPhysWorld2D* world = static_cast<ChipmunkPhysWorld2D*>(cpSpaceGetUserData(space));
				ChipmunkRigidBody2D* firstRigidBody = static_cast<ChipmunkRigidBody2D*>(cpBodyGetUserData(firstBody));
				ChipmunkRigidBody2D* secondRigidBody = static_cast<ChipmunkRigidBody2D*>(cpBodyGetUserData(secondBody));

				ChipmunkArbiter2D arbiter(arb);

				const Callback* customCallbacks = static_cast<const Callback*>(data);
				if (customCallbacks->preSolveCallback(*world, arbiter, *firstRigidBody, *secondRigidBody, customCallbacks->userdata))
					return cpTrue;
				else
					return cpFalse;
			};
		}
		else
		{
			handler->preSolveFunc = [](cpArbiter*, cpSpace*, void*) -> cpBool
			{
				return cpTrue;
			};
		}

		if (callbackFunctions->postSolveCallback)
		{
			handler->postSolveFunc = [](cpArbiter* arb, cpSpace* space, void *data)
			{
				cpBody* firstBody;
				cpBody* secondBody;
				cpArbiterGetBodies(arb, &firstBody, &secondBody);

				ChipmunkPhysWorld2D* world = static_cast<ChipmunkPhysWorld2D*>(cpSpaceGetUserData(space));
				ChipmunkRigidBody2D* firstRigidBody = static_cast<ChipmunkRigidBody2D*>(cpBodyGetUserData(firstBody));
				ChipmunkRigidBody2D* secondRigidBody = static_cast<ChipmunkRigidBody2D*>(cpBodyGetUserData(secondBody));

				ChipmunkArbiter2D arbiter(arb);

				const Callback* customCallbacks = static_cast<const Callback*>(data);
				customCallbacks->postSolveCallback(*world, arbiter, *firstRigidBody, *secondRigidBody, customCallbacks->userdata);
			};
		}
		else
		{
			handler->postSolveFunc = [](cpArbiter*, cpSpace*, void*)
			{
			};
		}
	}

	void ChipmunkPhysWorld2D::OnRigidBodyMoved(ChipmunkRigidBody2D* oldPointer, ChipmunkRigidBody2D* newPointer)
	{
		auto it = m_rigidPostSteps.find(oldPointer);
		if (it == m_rigidPostSteps.end())
			return; //< Shouldn't happen

		m_rigidPostSteps.emplace(std::make_pair(newPointer, std::move(it->second)));
		m_rigidPostSteps.erase(oldPointer);
	}

	void ChipmunkPhysWorld2D::OnRigidBodyRelease(ChipmunkRigidBody2D* rigidBody)
	{
		m_rigidPostSteps.erase(rigidBody);
	}

	void ChipmunkPhysWorld2D::RegisterPostStep(ChipmunkRigidBody2D* rigidBody, PostStep&& func)
	{
		// If space isn't locked, no need to wait
		if (!cpSpaceIsLocked(m_handle))
		{
			func(rigidBody);
			return;
		}

		auto it = m_rigidPostSteps.find(rigidBody);
		if (it == m_rigidPostSteps.end())
		{
			PostStepContainer postStep;
			postStep.onMovedSlot.Connect(rigidBody->OnRigidBody2DMove, this, &ChipmunkPhysWorld2D::OnRigidBodyMoved);
			postStep.onReleaseSlot.Connect(rigidBody->OnRigidBody2DRelease, this, &ChipmunkPhysWorld2D::OnRigidBodyRelease);

			it = m_rigidPostSteps.insert(std::make_pair(rigidBody, std::move(postStep))).first;
		}

		it->second.funcs.emplace_back(std::move(func));
	}
}