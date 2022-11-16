#pragma once

#ifdef SB_PLATFORM_WINDOWS
	#ifdef SB_BUILD_DLL
		#define BRAIN_API __declspec(dllexport)
	#else
#define BRAIN_API __declspec(dllimport)
	#endif
#else
	#error Spot Brain only supports Wndows!
#endif