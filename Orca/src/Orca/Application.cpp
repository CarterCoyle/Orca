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
		eventDispatcher ed(e);
		bool success;
		#ifdef LOG_ALL_EVENTS
		OC_CORE_TRACE("{0}", e.toString());
		#endif
		success = ed.Dispatch<windowCloseEvent>(BIND_EVENT_FN(Application::onWindowClose));
		success = ed.Dispatch<mouseButtonPressedEvent>(BIND_EVENT_FN(Application::dispatchTest));
	}

	bool Application::onWindowClose(windowCloseEvent& e)
	{
		running = false;
		return true;
	}

	bool Application::dispatchTest(Event& e)
	{
		return true;
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