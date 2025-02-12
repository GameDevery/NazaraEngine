// Copyright (C) 2025 Jérôme "SirLynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Widgets module"
// For conditions of distribution and use, see copyright notice in Export.hpp

namespace Nz
{
	inline void ButtonWidget::Disable()
	{
		return Enable(false);
	}

	inline bool ButtonWidget::IsEnabled() const
	{
		return m_isEnabled;
	}
}
