#include "OrcaPCH.h"
#include "GLFW/glfw3.h"


namespace Orca {

	class glWindow
	{
	public:
		GLFWwindow getWindow();
	private:
		GLFWwindow* win;
	};
}