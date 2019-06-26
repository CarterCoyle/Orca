#include "OrcaPCH.h"

#include "imGuiLayer.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "Orca/Application.h"

#define IMGUI_IMPL_API
#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl3.h"

namespace Orca {

	imGuiLayer::imGuiLayer(const std::string& name)
		: layer(name)
	{

	}

	imGuiLayer::~imGuiLayer()
	{

	}

	void imGuiLayer::onAttach()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); 
		(void)io;

		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

		ImGui::StyleColorsDark();

		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 1.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		Application& app = Application::getApp();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.getWindow().getNativeWindow());
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void imGuiLayer::onDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}
	void imGuiLayer::onImGuiRender()
	{
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}
	void imGuiLayer::begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}
	void imGuiLayer::end()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::getApp();
		io.DisplaySize = ImVec2(app.getWindow().getWidth(), app.getWindow().getHeight());

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* window = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(window);
		}
	}
}