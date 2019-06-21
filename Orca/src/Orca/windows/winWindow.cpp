#include "OrcaPCH.h"
#include "winWindow.h"

namespace Orca {

	static bool isGLFWInit = false; //used in assert to check glfw is only initalised once

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

			isGLFWInit = true;
		}

		glWindow = glfwCreateWindow(wWinProps.width, wWinProps.height, wWinProps.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(glWindow);
		glfwSetWindowUserPointer(glWindow, &wWinProps);
		setVSync(true);
	}

	void winWindow::Shutdown()
	{
		glfwDestroyWindow(glWindow);
	}
}