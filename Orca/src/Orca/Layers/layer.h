#pragma once
#include "OrcaPCH.h"
#include "Orca/Events/Event.h"

namespace Orca {

	class ORCA_API layer
	{
	public:
		layer(const std::string& name = "layer");
		virtual ~layer();

		virtual void onAttach() {};
		virtual void onDetach() {};
		virtual void onImGuiRender() {};
		virtual void onUpdate() {};
		virtual void onEvent(Event& e) {};

		inline const std::string& getName() const { return debugName; }

	protected:
		std::string debugName;
	};
}