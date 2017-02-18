#include "WorldConstructor.hpp"

namespace pi
{
	float* WorldConstructor::heightMap;
	std::vector<int> WorldConstructor::id;

	uint8_t WorldConstructor::getCellID(uint8_t number)
	{
		return heightMap[number] / (1.0f / id.size());
	}

	void WorldConstructor::constructSingleCell(uint8_t number, TextureCache * textureCache)
	{
		MapManager::AddCell(number, getCellID(number), nullptr/*&textureCache->get(constants::worldConstructor::TEXTURE_FILE_PATH)*/, constants::worldConstructor::CELL);
	}

	void WorldConstructor::loadCellTypes()
	{
		std::ifstream input(constants::worldConstructor::ID_FILE_PATH);
		int tempID;

		while (input >> tempID) id.push_back(tempID);
	}

	void WorldConstructor::ConstructWorld(int width, int height, int seed, int accuracy, TextureCache * textureCache)
	{
		heightMap = WorldHeightmapGenerator::Generate(width, height, seed, accuracy);
		loadCellTypes();

		MapManager::SetUnitWorldSize(sf::Vector2i(width, height));

		for (uint8_t i = 0; i < width*height; ++i)
			constructSingleCell(i, textureCache);

		MapManager::FinalizeLogicPartOfMap();
	}

}

