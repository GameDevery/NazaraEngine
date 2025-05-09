// Copyright (C) 2025 Jérôme "SirLynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Vulkan renderer"
// For conditions of distribution and use, see copyright notice in Export.hpp

namespace Nz::Vk
{
	inline bool DescriptorPool::Create(Device& device, UInt32 maxSets, const VkDescriptorPoolSize& poolSize, VkDescriptorPoolCreateFlags flags, const VkAllocationCallbacks* allocator)
	{
		VkDescriptorPoolCreateInfo createInfo =
		{
			VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO, // VkStructureType                sType;
			nullptr,                                       // const void*                    pNext;
			flags,                                         // VkDescriptorPoolCreateFlags    flags;
			maxSets,                                       // uint32_t                       maxSets;
			1U,                                            // uint32_t                       poolSizeCount;
			&poolSize                                      // const VkDescriptorPoolSize*    pPoolSizes;
		};

		return Create(device, createInfo, allocator);
	}

	inline bool DescriptorPool::Create(Device& device, UInt32 maxSets, UInt32 poolSizeCount, const VkDescriptorPoolSize* poolSize, VkDescriptorPoolCreateFlags flags, const VkAllocationCallbacks* allocator)
	{
		VkDescriptorPoolCreateInfo createInfo =
		{
			VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO, // VkStructureType                sType;
			nullptr,                                       // const void*                    pNext;
			flags,                                         // VkDescriptorPoolCreateFlags    flags;
			maxSets,                                       // uint32_t                       maxSets;
			poolSizeCount,                                 // uint32_t                       poolSizeCount;
			poolSize                                       // const VkDescriptorPoolSize*    pPoolSizes;
		};

		return Create(device, createInfo, allocator);
	}

	inline VkResult DescriptorPool::CreateHelper(Device& device, const VkDescriptorPoolCreateInfo* createInfo, const VkAllocationCallbacks* allocator, VkDescriptorPool* handle)
	{
		return device.vkCreateDescriptorPool(device, createInfo, allocator, handle);
	}

	inline void DescriptorPool::DestroyHelper(Device& device, VkDescriptorPool handle, const VkAllocationCallbacks* allocator)
	{
		return device.vkDestroyDescriptorPool(device, handle, allocator);
	}
}
