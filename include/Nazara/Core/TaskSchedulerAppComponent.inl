// Copyright (C) 2025 Jérôme "SirLynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Core module"
// For conditions of distribution and use, see copyright notice in Export.hpp

namespace Nz
{
	inline TaskSchedulerAppComponent::TaskSchedulerAppComponent(ApplicationBase& app, unsigned int workerCount) :
	ApplicationComponent(app),
	TaskScheduler(workerCount)
	{
	}
}
