#include "WorldConstructor.hpp"

namespace pi
{
	float* WorldConstructor::heightMap;
	int WorldConstructor::ammountOfTypes;

	void WorldConstructor::constructSingleCell( uint8_t number )
	{
		MapManager::AddCell( number, getCellID( number ) );
	}

	void WorldConstructor::ConstructWorld( int width, int height, int seed, int accuracy )
	{

		heightMap = WorldHeightmapGenerator::Generate( width, height, seed, accuracy );

		std::ifstream input( "ammountOfCellTypes.txt" );
		input >> ammountOfTypes;

		MapManager::SetUnitWorldSize( sf::Vector2i( width, height ) );

		for ( uint16_t i = 0; i < width*height; ++i )
			constructSingleCell( heightMap[i] );

		MapManager::FinalizeLogicPartOfMap();
	}

}

