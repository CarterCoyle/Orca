#include "OrcaPCH.h"

#include "GLFW/glfw3.h"
#include "Application.h"

namespace Orca
{	
	Application* Application::instance = nullptr;

	Application::Application()
	{
		OC_ASSERT(!instance, "Application already running!");
		instance = this;
		appWindow = std::unique_ptr<window>(window::create());
		appImGuiLayer = new imGuiLayer();
		pushOverlay(appImGuiLayer);
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

		for (auto it = stack.end(); it != stack.begin();)
		{
			(*--it)->onEvent(e);
			if (e.getHandled())
				break;
		}

		success = ed.Dispatch<windowCloseEvent>(BIND_EVENT_FN(Application::onWindowClose));
	}

	bool Application::onWindowClose(windowCloseEvent& e)
	{
		stack.popOverlay(appImGuiLayer);
		delete appImGuiLayer;
		running = false;
		return true;
	}

	void Application::pushLayer(layer* layer)
	{
		layer->onAttach();
		stack.pushLayer(layer);
	}

	void Application::pushOverlay(layer* overlay)
	{
		overlay->onAttach();
		stack.pushOverlay(overlay);
	}

	void Application::run()
	{
		OC_CORE_INFO("ORCA INITIALISED!");

		while (running)
		{
			appWindow->onUpdate();
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			for (layer* layer : stack)
				layer->onUpdate();

			appImGuiLayer->begin();
			for (layer* layer : stack)
				layer->onImGuiRender();
			appImGuiLayer->end();
		}
	}
}