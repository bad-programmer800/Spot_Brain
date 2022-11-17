#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Brainspace {
	class BRAIN_API Log
	{
	public:
		static void Init(); // Static means their is only one instance.

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	// Look up inline meaning!!
		// What is a shared pointer?
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger; // creates private variable only used by GetCoreLogger
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define SB_CORE_TRACE(...)		::Brainspace::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SB_CORE_INFO(...)		::Brainspace::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SB_CORE_WARN(...)		::Brainspace::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SB_CORE_ERROR(...)		::Brainspace::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SB_CORE_FATAL(...)		::Brainspace::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define SB_TRACE(...)			::Brainspace::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SB_INFO(...)			::Brainspace::Log::GetClientLogger()->info(__VA_ARGS__)
#define SB_WARN(...)			::Brainspace::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SB_ERROR(...)			::Brainspace::Log::GetClientLogger()->error(__VA_ARGS__)
#define SB_FATAL(...)			::Brainspace::Log::GetClientLogger()->fatal(__VA_ARGS__)