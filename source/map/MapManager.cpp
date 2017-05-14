#include "MapManager.hpp"


namespace pi
{

	sf::Vector2i MapManager::GetUnitWorldSize() const
	{
		return MapManager::unitWorldSize;
	}

	void MapManager::createWorld( int mapNumber )
	{
		WorldConstructor worldConstructor;
		worldConstructor.CreateWorld( mapNumber, map, unitWorldSize );
	}

	bool MapManager::IsInMap( sf::Vector2i & unitPosition ) const
	{
		return IsInMap( unitPosition.x, unitPosition.y );
	}

	bool MapManager::IsInMap( unsigned int i, unsigned int j ) const
	{
		return i >= 0 && i < unitWorldSize.x &&
			j >= 0 && j < unitWorldSize.y;
	}

	void MapManager::addCell( int id, sf::Vector2i unitPosition )
	{
		map.emplace_back( id, unitPosition );
	}

}
