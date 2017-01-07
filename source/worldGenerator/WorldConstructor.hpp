#pragma once

#include <fstream>

#include "WorldHeightmapGenerator.hpp"
#include "engine/map/MapManager.hpp"
#include "engine/ResourceCache.hpp"

namespace pi
{
	class WorldConstructor final
	{
		WorldConstructor();

		//Returns type of Cell
		static uint8_t getCellID(uint8_t number);

		//Add single cell
		static void constructSingleCell(uint8_t number, TextureCache * textureCache);

		//Loades cell types to a vector of cells' ID
		static void loadCellTypes();
	public:

		//Creates a world (width x height) with given seed and accuracy
		static void constructWorld(int width, int height, int seed, int accuracy,TextureCache * textureCache);

	private:
		static float* heightMap;
		static std::vector<int> id;
	};
}

