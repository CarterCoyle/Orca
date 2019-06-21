#pragma once
#include "OrcaPCH.h"
#include "windows/window.h"	
#include "Events/Event.h"
#include "Log.h"


namespace Orca {
	class ORCA_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
		void onEvent(Event& e);
	private:
		std::unique_ptr<window> appWindow;
		bool running = true;
	};

	Application* createApplication();
}