#include "MapRenderer.hpp"


namespace pi
{
	std::vector<MapObject>* MapRenderer::objects = nullptr;


	void MapRenderer::draw(sf::RenderTarget& target)
	{
		if (objects == nullptr)
			return;

		for (auto& o : *objects)
		{
			target.draw(o);
		}
	}

	void MapRenderer::updateObjects(std::vector<MapObject>* obj)
	{
		objects = obj;
	}
}