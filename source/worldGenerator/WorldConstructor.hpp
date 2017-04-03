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
		static void ConstructWorld( int width, int height, int seed, int accuracy );

	private:
		static float* heightMap;
		static int ammountOfTypes;

		//Returns type of Cell
		static uint8_t getCellID( uint8_t number )
		{
			return heightMap[number] / (1.0f / (ammountOfTypes));
		}

		//Add single cell
		static void constructSingleCell( uint8_t number );
	};
}

