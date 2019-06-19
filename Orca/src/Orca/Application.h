#pragma once
#include "core.h"

namespace Orca {
	class ORCA_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
	};

	Application* createApplication();
}