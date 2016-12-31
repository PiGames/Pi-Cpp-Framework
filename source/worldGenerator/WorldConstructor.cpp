#include "WorldConstructor.hpp"

namespace pi
{
	float* WorldConstructor::heightMap;
	std::vector<int> WorldConstructor::id;

	uint8_t WorldConstructor::getCellID(uint8_t number)
	{
		return heightMap[number] / (1.0f / id.size());
	}

	void WorldConstructor::constructSingleCell(uint8_t number)
	{
		MapManager::AddCell(number,getCellID(number),/*texture*/,"Cell")
	}

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
		
		for (uint8_t i = 0; i < width*height; i++)
			constructSingleCell(i);
	}

}

