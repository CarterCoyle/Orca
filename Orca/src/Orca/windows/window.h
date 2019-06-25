#pragma once
#include "OrcaPCH.h"
#include "Orca/Events/Event.h"
#include "Orca/Events/keyEvent.h"
#include "Orca/Events/mouseEvent.h"
#include "Orca/Events/appEvent.h"

namespace Orca {

	struct winProperties
	{
		unsigned int width, height;
		std::string title;

		winProperties(const std::string& Title = "Orca",
			unsigned int Width = 1920,
			unsigned int Height = 1080)
			: title(Title), width(Width), height(Height)
		{

		}
	};

	class ORCA_API window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;	

		virtual ~window() {};

		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		virtual void setEventCallback(const EventCallbackFn& callback) = 0;	//takes a param of a void function with a reference to an event. This void function is then called after every event call back for this window
		virtual void setVSync(bool isEnabled) = 0;
		virtual bool isVSyncEnabled() const = 0;

		virtual void* getNativeWindow() const = 0;	//override in platform specific files to return a pointer to glWindow/HWND etc.
		static window* create(const winProperties& props = winProperties());
	};
}
