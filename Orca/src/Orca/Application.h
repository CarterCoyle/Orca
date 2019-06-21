#pragma once
#include "OrcaPCH.h"
#include "windows/window.h"	
#include "Events/Event.h"
#include "Events/keyEvent.h"
#include "Log.h"


namespace Orca {
	class ORCA_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
		void onEvent(Event& e);
		bool dispatchTest(Event& e);
	private:
		bool onWindowClose(windowCloseEvent& e);
		std::unique_ptr<window> appWindow;
		bool running = true;
	};

	Application* createApplication();
}