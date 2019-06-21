#pragma once
#include "OrcaPCH.h"
#include "windows/window.h"	
#include "Log.h"


namespace Orca {
	class ORCA_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
	private:
		std::unique_ptr<window> appWindow;
		bool running = true;
	};

	Application* createApplication();
}