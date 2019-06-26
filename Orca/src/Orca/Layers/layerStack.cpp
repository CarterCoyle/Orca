#include "OrcaPCH.h"
#include "layerStack.h"

namespace Orca {
	
	layerStack::layerStack()
	{
	}

	layerStack::~layerStack()
	{
		for (layer* layer : layers)
			delete layer;
	}

	void layerStack::pushLayer(layer* layer)
	{
		layers.emplace(layers.begin() + layerInsertIndex, layer);
		++layerInsertIndex;
	}

	void layerStack::pushOverlay(layer* overlay)
	{
		layers.emplace_back(overlay);
	}

	void layerStack::popLayer(layer* layer)
	{
		auto it = std::find(layers.begin(), layers.end(), layer);
		if (it != layers.end())
		{
			layers.erase(it);
			layerInsertIndex--;
		}
	}

	void layerStack::popOverlay(layer* overlay)
	{
		auto it = std::find(layers.begin(), layers.end(), overlay);
		if (it != layers.end())
			layers.erase(it);	
	}
}