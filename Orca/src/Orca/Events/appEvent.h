#pragma once
#include "Event.h"

namespace Orca {

	class ORCA_API windowResizeEvent : public Event
	{
	public:
		windowResizeEvent(unsigned int newWidth, unsigned int newHeight)
			:	width(newWidth), height(newHeight) {}

		inline unsigned int getWidth() const { return width; }
		inline unsigned int getHeight() const { return height; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "WindowResized: " << width << ", " << height;
			return ss.str();
		}

		EVENT_TYPE(windowResize)
		EVENT_CATEGORY(app)
	private:
		unsigned int width, height;
	};

	class ORCA_API windowCloseEvent : public Event
	{
	public:
		windowCloseEvent() {}

		EVENT_TYPE(windowClose)
		EVENT_CATEGORY(app)
	};
}