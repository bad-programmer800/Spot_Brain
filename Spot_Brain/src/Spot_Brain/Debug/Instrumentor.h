#pragma once

#include <algorithm>
#include <chrono>
#include <fstream>
#include <string>
#include <thread>

namespace Brain {

	struct ProfileResult
	{
		std::string Name;
		long long Start, End;
		std::thread::id ThreadID;
	};

	struct InstrumentationSession
	{
		std::string Name;
	};

	class Instrumentor
	{
	private:
		std::mutex m_Mutex;
		InstrumentationSession* m_CurrentSession;
		std::ofstream m_OutputStream;
	public:
		Instrumentor()
			: m_CurrentSession(nullptr)
		{
		}

		void BeginSession(const std::string& name, const std::string& filepath = "result.json")
		{
			std::lock_guard lock(m_Mutex);
			if (m_CurrentSession) {
				if (Log::GetCoreLogger()) {
					SB_CORE_ERROR("Instrumentor::BeginSession('{0}') when session '{1}' already open!", name, m_CurrentSession->Name);
				}
				InternalEndSession();
			}
			m_OutputStream.open(filepath);

			if (m_OutputStream.is_open())
			{
				m_CurrentSession = new InstrumentationSession({ name });
				WriteHeader();
			}
			else
			{
				if (Log::GetCoreLogger())
				{
					SB_CORE_ERROR("Instrumentor could not open results file '{0}'.", filepath);
				}
			}
		}

		void EndSession()
		{
			std::lock_guard lock(m_Mutex);
			InternalEndSession();
		}

		void WriteProfile(const ProfileResult& result)
		{
			std::stringstream json;

			std::string name = result.Name;
			std::replace(name.begin(), name.end(), '"', '\'');

			json << ",{";
			json << "\"cat\":\"function\",";
			json << "\"dur\":" << (result.End - result.Start) << ',';
			json << "\"name\":\"" << name << "\",";
			json << "\"ph\":\"x\",";
			json << "\"pid\":0,";
			json << "\"tid\":" << result.ThreadID << ",";
			json << "\"ts\":" << result.Start;
			json << "}";

			std::lock_guard lock(m_Mutex);
			if (m_CurrentSession)
			{
				m_OutputStream << json.str();
				m_OutputStream.flush();
			}
		}

		static Instrumentor& Get()
		{
			static Instrumentor instance;
			return instance;
		}
	private:
		void WriteHeader()
		{
			m_OutputStream << "{\"otherData\": {}, \"traceEvents\":[{}";
			m_OutputStream.flush();
		}

		void WriteFooter()
		{
			m_OutputStream << "]}";
			m_OutputStream.flush();
		}

		void InternalEndSession()
		{
			if (m_CurrentSession)
			{
				WriteFooter();
				m_OutputStream.close();
				delete m_CurrentSession;
				m_CurrentSession = nullptr;
			}
		}
	};

	class InstrumentationTimer
	{
	public:
		InstrumentationTimer(const char* name)
			: m_Name(name), m_Stopped(false)
		{
			m_StartTimepoint = std::chrono::high_resolution_clock::now();
		}

		~InstrumentationTimer()
		{
			if (!m_Stopped)
				Stop();
		}

		void Stop()
		{
			auto endTimepoint = std::chrono::high_resolution_clock::now();

			long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
			long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

			Instrumentor::Get().WriteProfile({ m_Name, start, end, std::this_thread::get_id() });

			m_Stopped = true;
		}

		private:
			const char* m_Name;
			std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
			bool m_Stopped;

	};
}


#define SB_PROFILE 1
#if SB_PROFILE
	#define SB_PROFILE_BEGIN_SESSION(name, filepath) ::Brain::Instrumentor::Get().BeginSession(name, filepath)
	#define SB_PROFILE_END_SESSION() ::Brain::Instrumentor::Get().EndSession()
	#define SB_PROFILE_SCOPE(name) ::Brain::InstrumentationTimer timer##__LINE__(name);
	#define SB_PROFILE_FUNCTION() SB_PROFILE_SCOPE(__FUNCSIG__)
#else
	#define SB_PROFILE_BEGIN_SESSION(name, filepath)
	#define SB_PROFILE_END_SESSION()
	#define SB_PROFILE_SCOPE(name)
	#define SB_PROFILE_FUNCTION()
#endif




