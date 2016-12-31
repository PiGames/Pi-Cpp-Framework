#include "WorldConstructor.hpp"

namespace pi
{
	float* WorldConstructor::heightMap;
	std::vector<int> WorldConstructor::id;

	void WorldConstructor::loadCellTypes()
	{
		std::ifstream input("id.txt");
		int tempID;

		while (input >> tempID) id.push_back(tempID);
	}

	void WorldConstructor::ConstructWorld(int width, int height, int seed, int accuracy)
	{
		heightMap = WorldGenerator::Generate(width,height,seed,accuracy);

		loadCellTypes();
	}

}

