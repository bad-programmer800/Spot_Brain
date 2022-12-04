#include "sbpch.h"
#include "Spot_Brain/Core/Input.h"

#ifdef SB_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsInput.h"
#endif

namespace Brain {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
		#ifdef SB_PLATFORM_WINDOWS
			return CreateScope<WindowsInput>();
		#else
			SB_CORE_ASSERT(false, "Unknown platform!");
			return nullptr;
		#endif
	}

}