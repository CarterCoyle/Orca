#include "OrcaPCH.h"
#include "window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Orca {

	class ORCA_API winWindow : public window
	{
	public:
		winWindow(const winProperties& props);
		virtual ~winWindow();

		void onUpdate() override;

		unsigned int getWidth() const override;
		unsigned int getHeight() const override;

		void setEventCallback(const EventCallbackFn& callback) override;
		void setVSync(bool enabled) override;
		bool isVSyncEnabled() const override;

		inline virtual void* getNativeWindow() const override { return glWindow; }
	private:
		void setCallbacks();
		virtual void Init(const winProperties& props);
		virtual void Shutdown();

		struct windowsWinProp
		{
			unsigned int width, height;
			std::string title;
			bool vsync;	
			EventCallbackFn callback;	//set to an event. Use bind macro later with SetEventCallback to bind void function. See BIND_EVENT_FN
		};

		windowsWinProp wWinProps;
		GLFWwindow* glWindow;
	};
}