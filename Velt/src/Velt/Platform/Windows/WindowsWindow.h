#pragma once

#include <memory>
#include <string>
#include <vulkan/vulkan.h>

struct SDL_Window;

namespace Velt
{
	class Application;
	class Window;
}

namespace Velt::Renderer
{
	class Context;
}

namespace Velt::Renderer::Vulkan
{
	class VulkanSwapchain;
}

namespace Velt::Windows
{
	class VELT_API WindowsWindow : public Velt::Window
	{
	public:
		WindowsWindow(const Velt::WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		u32 GetWidth() const override;
		u32 GetHeight() const override;
		bool IsVsync() const override;

		void SetVsync(bool enable) override;
		void SetResizable(bool enable) override;
		void* GetNativeHandle() const override;

		Renderer::Vulkan::VulkanSwapchain& GetSwapchain();
		void CreateWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

	private:
		SDL_Window* m_Window = nullptr;
		Renderer::Vulkan::VulkanSwapchain* m_Swapchain = nullptr;
		std::unique_ptr<Renderer::Context> m_Context;

		void Init(const Velt::WindowProps& props);
		void Shutdown();

		struct WindowData
		{
			std::string m_Title;
			u32 m_Width = 0, m_Height = 0;
			bool m_bVsync = false;
			bool m_bResizable = false;
		};

		WindowData m_Data;
	};
}
