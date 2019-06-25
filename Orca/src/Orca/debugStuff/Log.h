#pragma once
#include "Orca/core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Orca{

	class ORCA_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() {
			return s_CoreLogger;
		}
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() {
			return s_ClientLogger;
		}
		Log();
		~Log();
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;		//declares a log for both the engine and the client app
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define OC_CORE_TRACE(...)	::Orca::Log::getCoreLogger()->trace(__VA_ARGS__)
#define OC_CORE_INFO(...)	::Orca::Log::getCoreLogger()->info(__VA_ARGS__)
#define OC_CORE_WARN(...)	::Orca::Log::getCoreLogger()->warn(__VA_ARGS__)
#define OC_CORE_ERROR(...)	::Orca::Log::getCoreLogger()->error(__VA_ARGS__)
#define OC_CORE_FATAL(...)	::Orca::Log::getCoreLogger()->fatal(__VA_ARGS__)

//client log macros
#define OC_CLIENT_TRACE(...)	::Orca::Log::getClientLogger()->trace(__VA_ARGS__)
#define OC_CLIENT_INFO(...)		::Orca::Log::getClientLogger()->info(__VA_ARGS__)
#define OC_CLIENT_WARN(...)		::Orca::Log::getClientLogger()->warn(__VA_ARGS__)
#define OC_CLIENT_ERROR(...)	::Orca::Log::getClientLogger()->error(__VA_ARGS__)
#define OC_CLIENT_FATAL(...)	::Orca::Log::getClientLogger()->fatal(__VA_ARGS__)