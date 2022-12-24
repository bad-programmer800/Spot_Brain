#pragma once

#include "Spot_Brain/Core/Base.h"
#include "Spot_Brain/Core/Log.h"

#include <filesystem>

#ifdef SB_ENABLE_ASSERTS

	#define SB_INTERNAL_ASSERT_IMPL(type, check, msg, ...) {if(!(check)) {SB##type##ERROR(msg, __VA_ARGS__); SB_DEBUGBREAK();}}
	#define SB_INTERNAL_ASSERT_WITH_MSG(type, check, ...) SB_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define SB_INTERNAL_ASSERT_NO_MSG(type, check) SB_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", SB_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define SB_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define SB_INTERNAL_ASSERT_GET_MACRO(...) SB_EXPAND_MACRO(SB_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, SB_INTERNAL_ASSERT_WITH_MSG, SB_INTERNAL_ASSERT_NO_MSG))

	#define SB_ASSERT(...) SB_EXPAND_MACRO(SB_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__))
	#define SB_CORE_ASSERT(...) SB_EXPAND_MACRO(SB_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__))
#else
	#define SB_ASSERT(...)
	#define SB_CORE_ASSERT(...)
#endif // SB_ENABLE_ASSERTS