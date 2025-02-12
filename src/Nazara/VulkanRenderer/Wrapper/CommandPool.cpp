// Copyright (C) 2025 Jérôme "SirLynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Vulkan renderer"
// For conditions of distribution and use, see copyright notice in Export.hpp

#include <Nazara/VulkanRenderer/Wrapper/CommandPool.hpp>
#include <Nazara/VulkanRenderer/Wrapper/CommandBuffer.hpp>

namespace Nz::Vk
{
	CommandBuffer CommandPool::AllocateCommandBuffer(VkCommandBufferLevel level)
	{
		VkCommandBufferAllocateInfo createInfo =
		{
			VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
			nullptr,
			m_handle,
			level,
			1U
		};

		VkCommandBuffer handle = VK_NULL_HANDLE;
		m_lastErrorCode = m_device->vkAllocateCommandBuffers(*m_device, &createInfo, &handle);

		return CommandBuffer(*this, handle);
	}

	std::vector<CommandBuffer> CommandPool::AllocateCommandBuffers(UInt32 commandBufferCount, VkCommandBufferLevel level)
	{
		VkCommandBufferAllocateInfo createInfo =
		{
			VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
			nullptr,
			m_handle,
			level,
			commandBufferCount
		};

		std::vector<VkCommandBuffer> handles(commandBufferCount, VK_NULL_HANDLE);
		m_lastErrorCode = m_device->vkAllocateCommandBuffers(*m_device, &createInfo, handles.data());
		if (m_lastErrorCode != VkResult::VK_SUCCESS)
			return std::vector<CommandBuffer>();

		std::vector<CommandBuffer> commandBuffers;
		for (UInt32 i = 0; i < commandBufferCount; ++i)
			commandBuffers.emplace_back(CommandBuffer(*this, handles[i]));

		return commandBuffers;
	}
}
