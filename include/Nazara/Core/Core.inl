// Copyright (C) 2023 Jérôme "Lynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Core module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#include <Nazara/Core/Core.hpp>
#include <Nazara/Core/Debug.hpp>

namespace Nz
{
	inline const HardwareInfo& Core::GetHardwareInfo() const
	{
		return *m_hardwareInfo;
	}
}

#include <Nazara/Core/DebugOff.hpp>
