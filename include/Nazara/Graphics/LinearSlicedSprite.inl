// Copyright (C) 2023 Jérôme "Lynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Graphics module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#include <Nazara/Graphics/LinearSlicedSprite.hpp>
#include <algorithm>
#include <cassert>
#include <Nazara/Graphics/Debug.hpp>

namespace Nz
{
	inline void LinearSlicedSprite::AddSection(float size, float textureCoord)
	{
		NazaraAssert(m_sectionCount < m_sections.size(), "too many sections");

		auto& section = m_sections[m_sectionCount++];
		section.size = size;
		section.textureCoord = textureCoord;

		UpdateVertices();
	}

	inline void LinearSlicedSprite::Clear()
	{
		m_sectionCount = 0;

		UpdateVertices();
	}

	inline const Color& LinearSlicedSprite::GetColor() const
	{
		return m_color;
	}

	inline auto LinearSlicedSprite::GetOrientation() const -> Orientation
	{
		return m_orientation;
	}

	inline const Vector2f& LinearSlicedSprite::GetOrigin() const
	{
		return m_origin;
	}

	inline auto LinearSlicedSprite::GetSection(std::size_t sectionIndex) const -> const Section&
	{
		NazaraAssert(sectionIndex < m_sectionCount, "out of range section");
		return m_sections[sectionIndex];
	}

	inline std::size_t LinearSlicedSprite::GetSectionCount() const
	{
		return m_sectionCount;
	}

	inline float LinearSlicedSprite::GetSize() const
	{
		return m_size;
	}

	inline const Rectf& LinearSlicedSprite::GetTextureCoords() const
	{
		return m_textureCoords;
	}

	inline void LinearSlicedSprite::SetColor(const Color& color)
	{
		m_color = color;

		UpdateVertices();
	}

	inline void LinearSlicedSprite::RemoveSection(std::size_t sectionIndex)
	{
		NazaraAssert(sectionIndex < m_sectionCount, "out of range section");
		if (m_sectionCount >= sectionIndex + 1)
			std::move(m_sections.begin() + sectionIndex + 1, m_sections.begin() + m_sectionCount, m_sections.begin() + sectionIndex);

		m_sectionCount--;

		UpdateVertices();
	}

	inline void LinearSlicedSprite::SetMaterial(std::shared_ptr<MaterialInstance> material)
	{
		assert(material);

		if (m_material != material)
		{
			OnMaterialInvalidated(this, 0, material);
			m_material = std::move(material);

			OnElementInvalidated(this);
		}
	}

	inline void LinearSlicedSprite::SetOrigin(const Vector2f& origin)
	{
		m_origin = origin;

		UpdateVertices();
	}

	inline void LinearSlicedSprite::SetSection(std::size_t sectionIndex, float size, float textureCoord)
	{
		NazaraAssert(sectionIndex < m_sectionCount, "out of range section");

		auto& section = m_sections[sectionIndex];
		section.size = size;
		section.textureCoord = textureCoord;

		UpdateVertices();
	}

	inline void LinearSlicedSprite::SetSectionSize(std::size_t sectionIndex, float size)
	{
		NazaraAssert(sectionIndex < m_sectionCount, "out of range section");

		auto& section = m_sections[sectionIndex];
		section.size = size;

		UpdateVertices();
	}

	inline void LinearSlicedSprite::SetSectionTextureCoord(std::size_t sectionIndex, float textureCoord)
	{
		NazaraAssert(sectionIndex < m_sectionCount, "out of range section");

		auto& section = m_sections[sectionIndex];
		section.textureCoord = textureCoord;

		UpdateVertices();
	}

	inline void LinearSlicedSprite::SetSize(float size)
	{
		NazaraAssert(size >= 0.f, "size must be positive");

		m_size = size;

		UpdateVertices();
	}

	inline void LinearSlicedSprite::SetTextureCoords(const Rectf& textureCoords)
	{
		m_textureCoords = textureCoords;

		UpdateVertices();
	}

	inline void LinearSlicedSprite::SetTextureRect(const Rectf& textureRect)
	{
		Vector2f invTextureSize = 1.f / Vector2f(Vector2ui(GetTextureSize()));
		return SetTextureCoords(Rectf(textureRect.x * invTextureSize.x, textureRect.y * invTextureSize.y, textureRect.width * invTextureSize.x, textureRect.height * invTextureSize.y));
	}
}

#include <Nazara/Graphics/DebugOff.hpp>
