#pragma once

#include <memory>

#include "PlatformDetection.h"

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

#define SB_EXPAND_MACRO(x) x
#define SB_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define SB_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) {return this->fn(std::forward<decltype(args)>(args)...);}


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

#include "Spot_Brain/Core/Log.h"
#include "Spot_Brain/Core/Assert.h"