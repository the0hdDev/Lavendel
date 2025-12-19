#include "WindowsWindow.h"

namespace Velt 
{
	Velt::Window* Velt::Window::Create(const WindowProps& props)
	{
		VT_PROFILE_FUNCTION();
		return new WindowsWindow(props);
	}
}


namespace Velt::Windows
{
	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		VT_PROFILE_FUNCTION();
	}

	void WindowsWindow::OnUpdate()
	{
		VT_PROFILE_FUNCTION();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		VT_PROFILE_FUNCTION();
	}

	void WindowsWindow::Shutdown()
	{
		VT_PROFILE_FUNCTION();
	}

	void WindowsWindow::setEventCallback(const EventCallbackFn& callback)
	{
		VT_PROFILE_FUNCTION();
	}

	void WindowsWindow::setVsync(bool enable) const
	{
		VT_PROFILE_FUNCTION();
	}

	void WindowsWindow::setResizable(bool enable) const
	{
		VT_PROFILE_FUNCTION();
	}

}