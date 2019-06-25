#include "OrcaPCH.h"
#include "Orca/Layers/layer.h"
#include "Orca/openGlGUI/imGUIOpenGlRenderer.h"
#include "GLFW/glfw3.h"
#include "Orca/Application.h"

namespace Orca {

	class ORCA_API imGuiLayer : public layer
	{
	public:
		imGuiLayer(const std::string& name = "imguiLayer");
		~imGuiLayer();

		void onAttach() override;
		void onDetach() override;
		void onUpdate() override;
		void onEvent(Event& e) override;
	private:
		bool onMouseButtonPressed(mouseButtonPressedEvent& e);
		bool onMouseButtonReleased(mouseButtonReleasedEvent& e);
		bool onMouseMoved(mouseMovedEvent& e);
		bool onMouseScrolled(mouseScrolledEvent& e);
		bool onKeyPressed(keyPressedEvent& e);
		bool onKeyReleased(keyReleasedEvent& e);
		bool onKeyTyped(keyTypedEvent& e);
		bool onWindowResize(windowResizeEvent& e);

		float layerTime = 0.0f;
		Application& app = Application::getApp();
	};
}