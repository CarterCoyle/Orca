#pragma once
#include "OrcaPCH.h"

namespace Orca {

	class ORCA_API input
	{
	public:
		inline static bool isKeyPressed(int keycode) { return instance->isKeyPressedImpl(keycode); }
		inline static bool isMouseButtonPressed(int button) { return instance->isMouseButtonPressedimpl(button); }
		inline static float getMouseX() { return instance->getMouseXImpl(); }
		inline static float getMouseY() { return instance->getMouseYImpl(); }
		inline static std::pair<float, float> getMousePos() { return instance->getMousePosImpl(); }
	protected:
		virtual bool isKeyPressedImpl(int keycode) = 0;
		virtual bool isMouseButtonPressedimpl(int button) = 0;
		virtual float getMouseXImpl() = 0;
		virtual float getMouseYImpl() = 0;
		virtual std::pair<float, float> getMousePosImpl() = 0;
	private:
		static input* instance;
	};
}
