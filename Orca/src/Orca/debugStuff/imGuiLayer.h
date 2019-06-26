#pragma once

#include "Orca/Layers/layer.h"

namespace Orca {

	class ORCA_API imGuiLayer : public layer
	{
	public:
		imGuiLayer(const std::string& name = "imguiLayer");
		~imGuiLayer();

		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onImGuiRender() override;

		void begin();
		void end();
	private:
		float layerTime = 0.0f;
	};
}