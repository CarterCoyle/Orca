#pragma once
#include "OrcaPCH.h"

namespace Orca {

	enum class EventType
	{
		None = 0,
		windowClose, windowResize, windowFocus, windowLostFocus, windowMoved,
		appTick, appUpdate, appRender,
		keyPressed, keyReleased, keyTyped,
		mouseButtonPressed, mouseButtonReleased, mouseMoved, mouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		app,
		Input,
		key,
		mouse,
		mouseButton
	};

#define EVENT_TYPE(type) static EventType getStaticType() { return EventType::##type; }\
						 virtual EventType getEventType() const override { return getStaticType(); }\
						 virtual const char* getName() const override { return #type; }

#define EVENT_CATEGORY(category) virtual EventCategory getCategory() const override { return category; }

	class ORCA_API Event
	{
		friend class eventDispatcher; 

	public:
		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual EventCategory getCategory() const = 0;
		virtual std::string toString() const { return getName(); }
		static EventType getStaticType() { return EventType::None; }
		bool getHandled() { return isHandled; }

		inline bool isInCategory(EventCategory cat)
		{
			if (cat == Input || cat == mouse)
				return (getCategory() >= cat);
			else
				return (getCategory() == cat);
		}

	protected:
		bool isHandled = false;
	};

	class ORCA_API eventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		eventDispatcher(Event& e)
			:	d_event(e) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)			//pass a boolean function with a param of any Event. If event matches the event used to construct dispatcher, the param function is executed
		{
			if (d_event.getEventType() == T::getStaticType())
			{
				d_event.isHandled = func(*(T*)& d_event);
				return true;
			}
			return false;
		}
	private:
		Event& d_event;
	};
}