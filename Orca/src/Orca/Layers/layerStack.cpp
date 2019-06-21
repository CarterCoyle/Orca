#include "OrcaPCH.h"
#include "layerStack.h"

namespace Orca {
	
	layerStack::layerStack()
	{
		layerInsert = layers.begin();
	}

	layerStack::~layerStack()
	{
		for (layer* layer : layers)
			delete layer;
	}

	void layerStack::pushLayer(layer* layer)
	{
		layerInsert = layers.emplace(layerInsert, layer);
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
			layerInsert--;
		}
	}

	void layerStack::popOverlay(layer* overlay)
	{
		auto it = std::find(layers.begin(), layers.end(), overlay);
		if (it != layers.end())
			layers.erase(it);	
	}
}