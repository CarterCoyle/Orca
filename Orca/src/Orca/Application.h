#pragma once
#include "Log.h"
#include "core.h"

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