#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Brain {
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
#define SB_CORE_TRACE(...)		::Brain::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SB_CORE_INFO(...)		::Brain::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SB_CORE_WARN(...)		::Brain::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SB_CORE_ERROR(...)		::Brain::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SB_CORE_CRITICAL(...)	::Brain::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define SB_TRACE(...)			::Brain::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SB_INFO(...)			::Brain::Log::GetClientLogger()->info(__VA_ARGS__)
#define SB_WARN(...)			::Brain::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SB_ERROR(...)			::Brain::Log::GetClientLogger()->error(__VA_ARGS__)
#define SB_CRITICAL(...)		::Brain::Log::GetClientLogger()->critical(__VA_ARGS__)