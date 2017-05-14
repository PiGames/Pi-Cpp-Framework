#pragma once

#include <fstream>
#include <string>
#include <vector>

#include <SFML/System/Vector2.hpp>

#include "map/Cell.hpp"
#include "Config.hpp"
#include "MapManager.hpp"


namespace pi
{
	class WorldConstructor
	{
	public:
		//Creates world 
		void CreateWorld( int mapNumber, std::vector<Cell>& map, sf::Vector2i& unitWorldSize ) const;
	};
}
