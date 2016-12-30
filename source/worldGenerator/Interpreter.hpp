#pragma once

#include <fstream>
#include "engine\map\MapManager.hpp"
#include "WorldGenerator.hpp"

namespace pi
{
	class Interpreter final
	{
		//Loades cell types to a vector of cells' ID
		static void loadCellTypes();
	public:

		//Creates a world (width x height) with given seed and accuracy
		static void ConstructWorld(int width, int height, int seed, int accuracy);

	private:
		static float* heightMap;
		static std::vector<int> id;
	};
}

