#include "WorldConstructor.hpp"

namespace pi
{
	float* WorldConstructor::heightMap;
	std::vector<int> WorldConstructor::id;

	void WorldConstructor::constructSingleCell( uint8_t number, sf::Texture * texture)
	{
		MapManager::AddCell( number, getCellID( number ), texture, constants::worldConstructor::CELL );
	}

	void WorldConstructor::loadCellTypes()
	{
		std::ifstream input( constants::worldConstructor::ID_FILE_PATH );
		int tempID;

		while ( input >> tempID ) id.push_back( tempID );
	}

	void WorldConstructor::ConstructWorld( int width, int height, int seed, int accuracy, TextureCache * textureCache )
	{

		heightMap = WorldHeightmapGenerator::Generate( width, height, seed, accuracy );
		loadCellTypes();

		MapManager::SetUnitWorldSize( sf::Vector2i( width, height ) );

		for ( uint16_t i = 0; i < width*height; ++i )
			constructSingleCell( i, nullptr/*&textureCache->Get( "data/textures/textureSheet.png" )*/ );

		MapManager::FinalizeLogicPartOfMap();
	}

}

