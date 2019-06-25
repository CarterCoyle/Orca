#include "OrcaPCH.h"
#include "winInput.h"


namespace Orca {

	input* input::instance = new winInput();

	bool winInput::isKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::getApp().getWindow().getNativeWindow());
		auto state = glfwGetKey(window, keycode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool winInput::isMouseButtonPressedimpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::getApp().getWindow().getNativeWindow());
		auto state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}

	float winInput::getMouseXImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::getApp().getWindow().getNativeWindow());
		double x, y;
		glfwGetCursorPos(window, &x, &y);

		return x;
	}

	float winInput::getMouseYImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::getApp().getWindow().getNativeWindow());
		double x, y;
		glfwGetCursorPos(window, &x, &y);

		return y;
	}

	std::pair<float, float> winInput::getMousePosImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::getApp().getWindow().getNativeWindow());
		double x, y;
		glfwGetCursorPos(window, &x, &y);

		return { x, y };
	}
}