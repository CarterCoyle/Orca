#pragma once
#include "Event.h"
#include <sstream>

namespace Orca {

	class ORCA_API keyEvent : public Event
	{
	public:
		inline int getKeyCode() const { return keyCode; }

		EVENT_CATEGORY(key)
	protected:
		keyEvent(int keycode)
			: keyCode(keycode) {}

		int keyCode;
	};

	class ORCA_API keyPressedEvent : public keyEvent
	{
	public:
		keyPressedEvent(int keycode, int repeatcount)
			:	keyEvent(keycode), repeatCount(repeatcount) {}

		inline int getrepeatCount() const { return repeatCount; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode;
			return ss.str();
		}

		EVENT_TYPE(keyPressed)
	private:
		int repeatCount;
	};

	class ORCA_API keyReleasedEvent : public keyEvent
	{
	public:
		keyReleasedEvent(int keycode)
			: keyEvent(keycode) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode;
			return ss.str();
		}
		EVENT_TYPE(keyReleased)

	};
}