#include "OrcaPCH.h"
#include "GLFW/glfw3.h"
#include "Application.h"


namespace Orca
{
	Application::Application()
	{
		
	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		OC_CORE_INFO("ORCA INITIALISED!");
		GLFWwindow* win = glfwCreateWindow(1920, 1080, "Orca", glfwGetPrimaryMonitor(), NULL);
		while (running)
		{
			
		}
	}
}