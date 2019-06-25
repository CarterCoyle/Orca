#include "OrcaPCH.h"
#include "winWindow.h"

namespace Orca {

	static bool isGLFWInit = false; //used in assert to check glfw is only initalised once

	static void GLFWErrorCallback(int errorNum, const char* description)	//passed to glfwSetErrorCallback so error messages are displayed
	{
		OC_CORE_ERROR("GLFW ERROR ({0}): {1}", errorNum, description);
	}

	window* window::create(const winProperties& props)
	{
		return new winWindow(props);
	}

	winWindow::winWindow(const winProperties& props)
	{
		Init(props);
	}

	winWindow::~winWindow()
	{
		Shutdown();
	}

	unsigned int winWindow::getWidth() const
	{
		return wWinProps.width;
	}

	unsigned int winWindow::getHeight() const
	{
		return wWinProps.height;
	}

	void winWindow::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(glWindow);
	}

	void winWindow::setEventCallback(const EventCallbackFn& callback)
	{
		wWinProps.callback = callback;
	}

	void winWindow::setVSync(bool enable)
	{
		if (enable)
			glfwSwapInterval(1);	//for this function, 1 means vSync is enabled and 0 = disabled
		else
			glfwSwapInterval(0);

		wWinProps.vsync = enable;
	}

	bool winWindow::isVSyncEnabled() const
	{
		return wWinProps.vsync;
	}

	void winWindow::Init(const winProperties& props)
	{
		wWinProps.height = props.height;
		wWinProps.width = props.width;
		wWinProps.title = props.title;

		OC_CORE_INFO("Creating winWindow {0} ({1}, {2})", wWinProps.title, wWinProps.width, wWinProps.height);

		if (!isGLFWInit)
		{
			int success = glfwInit();

			OC_ASSERT(success, "GLFW failed to initialise");

			glfwSetErrorCallback(GLFWErrorCallback);

			isGLFWInit = true;
		}

		glWindow = glfwCreateWindow(wWinProps.width, wWinProps.height, wWinProps.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(glWindow);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		OC_ASSERT(status, "GLAD failed to initialise");
		glfwSetWindowUserPointer(glWindow, &wWinProps);	//links pointer of our custom window properties to GLFWwindow instance
		setVSync(true);

		//set callbacks for window events. All passed as lambda functions. See definition below
		setCallbacks();
	}

	void winWindow::setCallbacks()
	{
		glfwSetWindowCloseCallback(glWindow, [](GLFWwindow* window)
			{
				windowsWinProp& props = *(windowsWinProp*)glfwGetWindowUserPointer(window);
				windowCloseEvent winEvent;
				props.callback(winEvent);
			});
		glfwSetWindowSizeCallback(glWindow, [](GLFWwindow* window, int width, int height)
			{
				windowsWinProp& props = *(windowsWinProp*)glfwGetWindowUserPointer(window);

				windowResizeEvent winEvent(width, height);
				props.width = width;
				props.height = height;
				props.callback(winEvent);
			});
		glfwSetKeyCallback(glWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				windowsWinProp& props = *(windowsWinProp*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					keyPressedEvent pressEvent(key, 0);
					props.callback(pressEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					keyReleasedEvent releaseEvent(key);
					props.callback(releaseEvent);
					break;
				}
				case GLFW_REPEAT:
				{
					keyPressedEvent repeatEvent(key, 1);	//TODO - replace '1' with actual repeat count
					props.callback(repeatEvent);
					break;
				}
				}
			});
		glfwSetMouseButtonCallback(glWindow, [](GLFWwindow* window, int button, int action, int mods)
			{
				windowsWinProp& props = *(windowsWinProp*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					mouseButtonPressedEvent pressEvent(button);
					props.callback(pressEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					mouseButtonReleasedEvent releaseEvent(button);
					props.callback(releaseEvent);
					break;
				}
				}
			});
		glfwSetScrollCallback(glWindow, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				windowsWinProp& props = *(windowsWinProp*)glfwGetWindowUserPointer(window);

				mouseScrolledEvent scrollEvent(xOffset, yOffset);
				props.callback(scrollEvent);
			});
		glfwSetCursorPosCallback(glWindow, [](GLFWwindow* window, double xPos, double yPos)
			{
				windowsWinProp& props = *(windowsWinProp*)glfwGetWindowUserPointer(window);

				mouseMovedEvent movEvent(xPos, yPos);
				props.callback(movEvent);
			});

		glfwSetCharCallback(glWindow, [](GLFWwindow* window, unsigned int keycode)
			{
				windowsWinProp& props = *(windowsWinProp*)glfwGetWindowUserPointer(window);

				keyTypedEvent type(keycode);
				props.callback(type);
			});
	}

	void winWindow::Shutdown()
	{
		glfwDestroyWindow(glWindow);
	}
}