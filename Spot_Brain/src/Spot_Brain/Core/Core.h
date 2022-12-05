#pragma once

#include <memory>

#ifdef SB_PLATFORM_WINDOWS
#if SB_DYNAMIC_LINK
	#ifdef SB_BUILD_DLL
		#define BRAIN_API __declspec(dllexport)
	#else
		#define BRAIN_API __declspec(dllimport)
	#endif
#else
	#define BRAIN_API
#endif
#else
	#error Spot Brain only supports Wndows!
#endif

#ifdef SB_DEBUG
	#if defined(SB_PLATFORM_WINDOWS)
		#define SB_DEBUGBREAK() __debugbreak()
	#elif defined(SB_PLATFORM_LINUX)
		#include <signal.h>
		#define SB_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!'"
	#endif // Platform
		#define SB_ENABLE_ASSERTS
#else
	#define SB_DEBUGBREAK()
#endif // SB_DEBUG


#ifdef SB_ENABLE_ASSERTS
	#define SB_ASSERT(x, ...) { if(!(x)) { SB_ERROR("Assertion Failed: {0}", __VA_ARGS__); SB_DEBUGBREAK();}}
	#define SB_CORE_ASSERT(x, ...) { if(!(x)) { SB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); SB_DEBUGBREAK();}}
#else
	#define SB_ASSERT(x, ...)
	#define SB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define SB_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Brain {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}