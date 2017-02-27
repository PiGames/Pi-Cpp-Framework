// Created by: mvxxx
#pragma once

#include <fstream>

#include "WorldHeightmapGenerator.hpp"
#include "engine/map/MapManager.hpp"
#include "engine/ResourceCache.hpp"

namespace pi
{
	//WorldConstructor class
	//It constructs world which is based on WorldHeightmapGenerator
	class WorldConstructor final
	{
	public:
		WorldConstructor() = delete;

		//Creates a world (width x height) with given seed and accuracy
		static void ConstructWorld( int width, int height, int seed, int accuracy, TextureCache * textureCache );

	private:
		static float* heightMap;
		static std::vector<int> id;

		//Returns type of Cell
		static uint8_t getCellID( uint8_t number )
		{
			return heightMap[number] / ( 1.0f / id.size() );
		}

		//Add single cell
		static void constructSingleCell( uint8_t number, TextureCache * textureCache );

		//Loades cell types to a vector of cells' ID
		static void loadCellTypes();
	};
}

