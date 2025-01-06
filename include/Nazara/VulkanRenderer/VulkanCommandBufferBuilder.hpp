// Copyright (C) 2025 Jérôme "SirLynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Vulkan renderer"
// For conditions of distribution and use, see copyright notice in Export.hpp

#pragma once

#ifndef NAZARA_VULKANRENDERER_VULKANCOMMANDBUFFERBUILDER_HPP
#define NAZARA_VULKANRENDERER_VULKANCOMMANDBUFFERBUILDER_HPP

#include <NazaraUtils/Prerequisites.hpp>
#include <Nazara/Renderer/CommandBufferBuilder.hpp>
#include <Nazara/VulkanRenderer/Export.hpp>
#include <Nazara/VulkanRenderer/Wrapper/CommandBuffer.hpp>

namespace Nz
{
	class VulkanRenderPass;

	class NAZARA_VULKANRENDERER_API VulkanCommandBufferBuilder final : public CommandBufferBuilder
	{
		public:
			inline VulkanCommandBufferBuilder(Vk::CommandBuffer& commandBuffer);
			VulkanCommandBufferBuilder(const VulkanCommandBufferBuilder&) = delete;
			VulkanCommandBufferBuilder(VulkanCommandBufferBuilder&&) noexcept = default;
			~VulkanCommandBufferBuilder() = default;

			void BeginDebugRegion(std::string_view regionName, const Color& color) override;
			void BeginRenderPass(const Framebuffer& framebuffer, const RenderPass& renderPass, const Recti& renderRect, const ClearValues* clearValues, std::size_t clearValueCount) override;

			void BindComputePipeline(const ComputePipeline& pipeline) override;
			void BindComputeShaderBinding(UInt32 set, const ShaderBinding& binding) override;
			void BindComputeShaderBinding(const RenderPipelineLayout& pipelineLayout, UInt32 set, const ShaderBinding& binding) override;
			void BindIndexBuffer(const RenderBuffer& indexBuffer, IndexType indexType, UInt64 offset = 0) override;
			void BindRenderPipeline(const RenderPipeline& pipeline) override;
			void BindRenderShaderBinding(UInt32 set, const ShaderBinding& binding) override;
			void BindRenderShaderBinding(const RenderPipelineLayout& pipelineLayout, UInt32 set, const ShaderBinding& binding) override;
			void BindVertexBuffer(UInt32 binding, const RenderBuffer& vertexBuffer, UInt64 offset = 0) override;

			void BlitTexture(const Texture& fromTexture, const Boxui& fromBox, TextureLayout fromLayout, const Texture& toTexture, const Boxui& toBox, TextureLayout toLayout, SamplerFilter filter) override;
			void BlitTextureToSwapchain(const Texture& fromTexture, const Boxui& fromBox, TextureLayout fromLayout, const Swapchain& swapchain, std::size_t imageIndex) override;

			void BuildMipmaps(Texture& texture, UInt8 baseLevel, UInt8 levelCount, PipelineStageFlags srcStageMask, PipelineStageFlags dstStageMask, MemoryAccessFlags srcAccessMask, MemoryAccessFlags dstAccessMask, TextureLayout oldLayout, TextureLayout newLayout) override;

			void CopyBuffer(const RenderBufferView& source, const RenderBufferView& target, UInt64 size, UInt64 sourceOffset = 0, UInt64 targetOffset = 0) override;
			void CopyBuffer(const UploadPool::Allocation& allocation, const RenderBufferView& target, UInt64 size, UInt64 sourceOffset = 0, UInt64 targetOffset = 0) override;
			void CopyTexture(const Texture& fromTexture, const Boxui& fromBox, TextureLayout fromLayout, const Texture& toTexture, const Vector3ui& toPos, TextureLayout toLayout) override;

			void Dispatch(UInt32 workgroupX, UInt32 workgroupY, UInt32 workgroupZ) override;

			void Draw(UInt32 vertexCount, UInt32 instanceCount = 1, UInt32 firstVertex = 0, UInt32 firstInstance = 0) override;
			void DrawIndexed(UInt32 indexCount, UInt32 instanceCount = 1, UInt32 firstIndex = 0, UInt32 vertexOffset = 0, UInt32 firstInstance = 0) override;

			void EndDebugRegion() override;
			void EndRenderPass() override;

			void InsertDebugLabel(std::string_view label, const Color& color) override;

			inline Vk::CommandBuffer& GetCommandBuffer();

			void MemoryBarrier(PipelineStageFlags srcStageMask, PipelineStageFlags dstStageMask, MemoryAccessFlags srcAccessMask, MemoryAccessFlags dstAccessMask) override;

			void NextSubpass() override;

			void PreTransferBarrier() override;
			void PostTransferBarrier() override;

			void SetScissor(const Recti& scissorRegion) override;
			void SetViewport(const Recti& viewportRegion) override;

			void TextureBarrier(PipelineStageFlags srcStageMask, PipelineStageFlags dstStageMask, MemoryAccessFlags srcAccessMask, MemoryAccessFlags dstAccessMask, TextureLayout oldLayout, TextureLayout newLayout, const Texture& texture) override;

			VulkanCommandBufferBuilder& operator=(const VulkanCommandBufferBuilder&) = delete;
			VulkanCommandBufferBuilder& operator=(VulkanCommandBufferBuilder&&) = delete;

		private:
			Vk::CommandBuffer& m_commandBuffer;
			const VulkanRenderPass* m_currentRenderPass;
			std::size_t m_currentSubpassIndex;
	};
}

#include <Nazara/VulkanRenderer/VulkanCommandBufferBuilder.inl>

#endif // NAZARA_VULKANRENDERER_VULKANCOMMANDBUFFERBUILDER_HPP
