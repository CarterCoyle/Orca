#pragma once
#include "OrcaPCH.h"
#include "layer.h"

namespace Orca {

	class ORCA_API layerStack
	{
	public:
		layerStack();
		~layerStack();

		void pushLayer(layer* layer);
		void pushOverlay(layer* overlay);
		void popLayer(layer* layer);
		void popOverlay(layer* overlay);

		std::vector<layer*>::iterator begin() { return layers.begin(); }
		std::vector<layer*>::iterator end() { return layers.end(); }

	private:
		std::vector<layer*> layers;
		std::vector<layer*>::iterator layerInsert;
	};
}