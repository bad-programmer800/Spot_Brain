#include "sbpch.h"
#include "Spot_Brain/Core/Window.h"

#ifdef SB_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Brain {

	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef SB_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#else
		SB_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}