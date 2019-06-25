#pragma once
#include "OrcaPCH.h"
#include "windows/window.h"	
#include "Layers/layerStack.h"
#include "Events/Event.h"
#include "Events/keyEvent.h"
#include "input/input.h"


namespace Orca {
	class ORCA_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
		void onEvent(Event& e);

		void pushLayer(layer* layer);
		void pushOverlay(layer* overlay);

		inline window& getWindow() { return *appWindow; }
		inline static Application& getApp() { return *instance; }
	private:
		bool onWindowClose(windowCloseEvent& e);
		std::unique_ptr<window> appWindow;
		bool running = true;
		layerStack stack;
		static Application* instance;
	};

	Application* createApplication();
}