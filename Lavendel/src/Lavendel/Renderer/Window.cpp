#include "Window.h"
#include "../Log.h"

namespace Lavendel {
	namespace RenderAPI {

		static bool s_GLFWInitialized = false;

		Window::Window(int width, int height, const std::string& title, bool bResizable) 
			: m_Width(width), m_Height(height), m_Title(title), m_Resizable(bResizable)
		{
			Init(width, height, title, bResizable);
		}

		Window::~Window()
		{
			Shutdown();
		}

		void Window::Init(int width, int height, const std::string& title, bool bResizable)
		{
			m_Width = width;
			m_Height = height;
			m_Title = title;
			m_Resizable = bResizable;

			if (!s_GLFWInitialized)
			{
				if (!glfwInit())
				{
					LV_CORE_ERROR("Failed to initialize GLFW!");
					return;
				}

				s_GLFWInitialized = true;
			}

			if (!bResizable)
			{
				glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
			}

			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

			m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

			if (!m_Window)
			{
				LV_CORE_ERROR("Failed to create GLFW window!");
				return;
			}
		}

		void Window::Shutdown()
		{
			if (m_Window)
			{
				glfwDestroyWindow(m_Window);
				m_Window = nullptr;
			}
		}

		void Window::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
		{
			if (glfwCreateWindowSurface(instance, m_Window, nullptr, surface) != VK_SUCCESS)
			{
				LV_CORE_ERROR("Failed to create window surface!");
				throw std::runtime_error("failed to create window surface!");
			}
		}

	}
}