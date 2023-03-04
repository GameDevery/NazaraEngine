// Copyright (C) 2023 Jérôme "Lynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Core module"
// For conditions of distribution and use, see copyright notice in Config.hpp

#include <Nazara/Core/Android/AndroidAssetDirResolver.hpp>
#include <Nazara/Core/Android/AndroidAssetStream.hpp>
#include <Nazara/Core/Error.hpp>
#include <Nazara/Core/Debug.hpp>

namespace Nz
{
	AndroidAssetDirResolver::~AndroidAssetDirResolver()
	{
		AAssetDir_close(m_assetDir);
	}

	void AndroidAssetDirResolver::ForEach(std::weak_ptr<VirtualDirectory> parent, FunctionRef<bool(std::string_view name, VirtualDirectory::Entry&& entry)> callback) const
	{
		AAssetDir_rewind(m_assetDir);
		while (const char* filename = AAssetDir_getNextFileName(m_assetDir))
		{
			std::string fullPath = m_basePath + "/" + filename;
			if (AAsset* asset = AAssetManager_open(m_manager, fullPath.c_str(), AASSET_MODE_RANDOM))
			{
				if (!callback(filename, VirtualDirectory::FileEntry{ std::make_shared<AndroidAssetStream>(std::move(fullPath), asset) }))
					return;
			}
		}
	}
	
	std::optional<VirtualDirectory::Entry> AndroidAssetDirResolver::Resolve(std::weak_ptr<VirtualDirectory> parent, const std::string_view* parts, std::size_t partCount) const
	{
		std::string fullPath = m_basePath;
		for (std::size_t i = 0; i < partCount; ++i)
		{
			if (!fullPath.empty())
				fullPath += "/";

			fullPath.append(parts[i]);
		}

		if (AAsset* asset = AAssetManager_open(m_manager, fullPath.c_str(), AASSET_MODE_RANDOM))
			return VirtualDirectory::FileEntry{ std::make_shared<AndroidAssetStream>(std::move(fullPath), asset) };
		else if (AAssetDir* assetDir = AAssetManager_openDir(m_manager, fullPath.c_str()))
		{
			VirtualDirectoryPtr virtualDir = std::make_shared<VirtualDirectory>(std::make_shared<AndroidAssetDirResolver>(m_manager, std::move(fullPath), assetDir), parent);
			return VirtualDirectory::DirectoryEntry{ { std::move(virtualDir) } };
		}

		return std::nullopt; //< not found
	}
}
