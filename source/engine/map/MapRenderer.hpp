#pragma once

#include "MapManager.hpp"

namespace pi
{
	/*
		Temporary, MapRenderer is using inefficient rendering method - every object is rendered.
		In future this will be changed. (It should be)
	*/
	class MapRenderer final
	{
	public:
		// Map Renderer, same as MapManager class, is static - you cannot make instance of it
		MapRenderer() = delete;

		static void draw(sf::RenderTarget& target);

		static void updateObjects(std::vector<MapObject>* obj);

	private:
		static std::vector<MapObject>* objects;
	};
}