#pragma once

#include "../Core.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace Lavendel {

    namespace RenderAPI {

        class LAVENDEL_API Window
        {

        public:
            Window(int width, int height, const std::string& title, bool bResizable = false);
            ~Window();

            Window(const Window&) = delete;
            void operator=(const Window&) = delete;

            void PollEvents() { glfwPollEvents(); }
            bool ShouldClose() { return glfwWindowShouldClose(m_Window); }
            void* GetNativeHandle() const { return m_Window; };
            void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
			VkExtent2D getExtent() { return { static_cast<uint32_t>(m_Width), static_cast<uint32_t>(m_Height) }; }

        private:
            void Init(int width, int height, const std::string& title, bool bResizable);
            void Shutdown();

            GLFWwindow* m_Window;
            int m_Width, m_Height;
            bool m_Resizable;
            std::string m_Title;


        };

    }
}