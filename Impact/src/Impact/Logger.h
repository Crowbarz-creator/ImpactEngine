#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Impact {

	class IMPACT_API Logger
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define IMP_CORE_TRACE(...)     ::Impact::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define IMP_CORE_INFO(...)	    ::Impact::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define IMP_CORE_WARN(...)	    ::Impact::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define IMP_CORE_ERROR(...)     ::Impact::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define IMP_CORE_CRITICAL(...)     ::Impact::Logger::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define IMP_TRACE(...)          ::Impact::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define IMP_INFO(...)           ::Impact::Logger::GetClientLogger()->info(__VA_ARGS__)
#define IMP_WARN(...)           ::Impact::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define IMP_ERROR(...)          ::Impact::Logger::GetClientLogger()->error(__VA_ARGS__)
#define IMP_CRITICAL(...)          ::Impact::Logger::GetClientLogger()->critical(__VA_ARGS__)