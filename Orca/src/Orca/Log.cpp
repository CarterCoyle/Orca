#include "OrcaPCH.h"
#include "Log.h"

namespace Orca {


	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("ORCA");
		OC_CORE_INFO("{0} logger initialised!", s_CoreLogger->name());
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		OC_CLIENT_INFO("{0} logger initialised!", s_ClientLogger->name());
		s_ClientLogger->set_level(spdlog::level::trace);
	}

	Log::Log()
	{

	}

	Log::~Log()
	{

	}
}