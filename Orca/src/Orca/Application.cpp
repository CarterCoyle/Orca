#include "OrcaPCH.h"
#include "GLFW/glfw3.h"
#include "Application.h"


namespace Orca
{
	Application::Application()
	{
		appWindow = std::unique_ptr<window>(window::create());
	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		OC_CORE_INFO("ORCA INITIALISED!");

		while (running)
		{
			appWindow->onUpdate();
		}
	}
}