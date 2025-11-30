#pragma once

#include "Lavendel/Renderer/Core/Device.h"
#include "Lavendel/Renderer/Framebuffer.h"
#include <cassert>
#include <vector>
#include <vulkan/vulkan.h>

namespace Lavendel::RenderAPI {

// ============================================
// Fehlende Typen die in der Basisklasse nicht existieren
// ============================================

enum class FramebufferTextureFormat {
  None = 0,

  // Color Formate
  RGBA8,
  RGBA16F,
  RED_INTEGER,

  // Depth/Stencil Formate
  DEPTH24STENCIL8,
  DEPTH32F
};

struct FramebufferTextureSpecification {
  FramebufferTextureFormat TextureFormat = FramebufferTextureFormat::None;

  FramebufferTextureSpecification() = default;
  FramebufferTextureSpecification(FramebufferTextureFormat format)
      : TextureFormat(format) {}
};

// ============================================
// VulkanFramebuffer Klasse
// ============================================

class VulkanFramebuffer : public Framebuffer {
public:
  VulkanFramebuffer(GPUDevice *device, const FramebufferSpecification &spec);

  virtual ~VulkanFramebuffer();

  void Invalidate();

  // Vulkan-spezifisch: RenderPass statt Bind/Unbind
  void BeginRenderPass(VkCommandBuffer commandBuffer);
  void EndRenderPass(VkCommandBuffer commandBuffer);

  // === Override Methoden aus Basisklasse ===
  virtual void Resize(u32 width, u32 height) override;
  virtual int ReadPixel(u32 attachmentIndex, int x, int y) override;
  virtual void ClearAttachment(uint32_t attachmentIndex, int value) override;

  virtual const FramebufferSpecification &GetSpecification() const override {
    return m_Specification;
  }

  // Doppelte Methode in Basisklasse (getSpecification und GetSpecification)
  virtual const FramebufferSpecification &getSpecification() const override {
    return m_Specification;
  }

  // === Vulkan-spezifische Getter ===

  VkImageView GetColorImageView(uint32_t index = 0) const {
    assert(index < m_ColorImageViews.size());
    return m_ColorImageViews[index];
  }

  VkImageView GetDepthImageView() const { return m_DepthImageView; }
  VkRenderPass GetRenderPass() const { return m_RenderPass; }
  VkFramebuffer GetVkFramebuffer() const { return m_Framebuffer; }

  VkImage GetColorImage(uint32_t index = 0) const {
    assert(index < m_ColorImages.size());
    return m_ColorImages[index];
  }

  size_t GetColorAttachmentCount() const { return m_ColorImageViews.size(); }

private:
  // Hilfsmethoden
  void CreateRenderPass();
  void CreateImages();
  void CreateImageViews();
  void CreateFramebuffer();
  void Cleanup();

  uint32_t FindMemoryType(uint32_t typeFilter,
                          VkMemoryPropertyFlags properties);

  static VkFormat
  FramebufferTextureFormatToVulkan(FramebufferTextureFormat format);
  static bool IsDepthFormat(FramebufferTextureFormat format);

private:
  // Vulkan Device Handles (nicht owned, nur Referenzen)
  GPUDevice *m_Device = VK_NULL_HANDLE;

  // Framebuffer Specification
  FramebufferSpecification m_Specification;

  // Attachment Specifications
  std::vector<FramebufferTextureSpecification> m_ColorAttachmentSpecifications;
  FramebufferTextureSpecification m_DepthAttachmentSpecification;

  // === Vulkan Ressourcen ===

  VkRenderPass m_RenderPass = VK_NULL_HANDLE;
  VkFramebuffer m_Framebuffer = VK_NULL_HANDLE;

  // Color Attachments
  std::vector<VkImage> m_ColorImages;
  std::vector<VkDeviceMemory> m_ColorMemories;
  std::vector<VkImageView> m_ColorImageViews;

  // Depth Attachment
  VkImage m_DepthImage = VK_NULL_HANDLE;
  VkDeviceMemory m_DepthMemory = VK_NULL_HANDLE;
  VkImageView m_DepthImageView = VK_NULL_HANDLE;

  // Für ReadPixel Operation
  VkBuffer m_StagingBuffer = VK_NULL_HANDLE;
  VkDeviceMemory m_StagingMemory = VK_NULL_HANDLE;

  // Für interne Operationen
  VkCommandPool m_CommandPool = VK_NULL_HANDLE;
  VkQueue m_GraphicsQueue = VK_NULL_HANDLE;

  static constexpr uint32_t s_MaxFramebufferSize = 8192;
};

} // namespace Lavendel::RenderAPI
