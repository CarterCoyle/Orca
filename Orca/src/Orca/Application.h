#pragma once
#include "OrcaPCH.h"
#include "Log.h"


namespace Orca {
	class ORCA_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
	private:
		bool running = true;
	};

	Application* createApplication();
}