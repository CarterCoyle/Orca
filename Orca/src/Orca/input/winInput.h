#include "OrcaPCH.h"
#include "input.h"
#include "Orca/Application.h"
#include <GLFW/glfw3.h>

namespace Orca {

	class winInput : public input
	{
		friend class input;
	public:
		
	protected:
		virtual bool isKeyPressedImpl(int keycode) override;
		virtual bool isMouseButtonPressedimpl(int button) override;
		virtual float getMouseXImpl() override;
		virtual float getMouseYImpl() override;
		virtual std::pair<float, float> getMousePosImpl() override;
	private:
	};
}