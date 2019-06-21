#include "OrcaPCH.h"
#include "GLFW/glfw3.h"
#include "Application.h"


namespace Orca
{
	#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		appWindow = std::unique_ptr<window>(window::create());
		appWindow->setEventCallback(BIND_EVENT_FN(Application::onEvent));	//binds window eventcallbacks to onEvent function. See below for onEvent
	}

	Application::~Application()
	{

	}

	void Application::onEvent(Event& e)
	{
		OC_CORE_INFO("{0}", e.getName());
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