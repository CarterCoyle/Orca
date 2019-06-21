#pragma once
#include "Event.h"
#include <sstream>

namespace Orca {

	class ORCA_API mouseMovedEvent : public Event
	{
	public:
		mouseMovedEvent(float x, float y)
			: mouseX(x), mouseY(y) {}

		inline float getX() const { return mouseX;  }
		inline float getY() const { return mouseY;  }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << mouseX << ", " << mouseY;
			return ss.str();
		}
		EVENT_TYPE(mouseMoved)
		EVENT_CATEGORY(mouse)
	private:
		float mouseX, mouseY;
	};

	class ORCA_API mouseScrolledEvent : public Event
	{
	public:
		mouseScrolledEvent(float xOff, float yOff)
			: xOffset(xOff), yOffset(yOff) {}

		inline float getYOffset() const { return yOffset; }
		inline float getXOffset() const { return xOffset; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << xOffset << ", " << yOffset;
			return ss.str();
		}
		
		EVENT_TYPE(mouseScrolled)
		EVENT_CATEGORY(mouse)
	private:
		float xOffset, yOffset;
	};

	class ORCA_API mouseButtonEvent : public Event
	{
	public:
		inline int getMouseButton() const { return mButton; }

		EVENT_CATEGORY(mouseButton)
	protected:
		mouseButtonEvent(int keycode)
			: mButton(keycode) {}
		int mButton;
	};

	class ORCA_API mouseButtonPressedEvent : public mouseButtonEvent
	{
	public:
		mouseButtonPressedEvent(int button)
			:	mouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressed: " << mButton;
			return ss.str();
		}

		EVENT_TYPE(mouseButtonPressed)
	};

	class ORCA_API mouseButtonReleasedEvent : public mouseButtonEvent
	{
	public:
		mouseButtonReleasedEvent(int button)
			: mouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleased: " << mButton;
			return ss.str();
		}

		EVENT_TYPE(mouseButtonReleased)
	};
}