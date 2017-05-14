#pragma once

#include <vector>

#include "Cell.hpp"
#include "logger/Logger.hpp"
#include "WorldConstructor.hpp"

namespace pi
{
	class MapManager
	{
	public:
		//Returns world size in units
		sf::Vector2i GetUnitWorldSize() const;

		void createWorld( int mapNumber );

		//Checks that object with given position is in map
		bool IsInMap( sf::Vector2i& unitPosition ) const;

		//Checks that object with given position is in map
		bool IsInMap( unsigned int i, unsigned int j ) const;

		//Adds new cell
		void addCell( int id, sf::Vector2i unitPosition );

		// Returns reference to map cells
		std::vector<Cell>& GetCells()
		{
			return this->map;
		}

	private:
		//Vector of cells which are the surface
		std::vector<Cell> map;

		//World size in units
		sf::Vector2i unitWorldSize{ 0,0 };

		//Dimensions of cell(in px)
		sf::Vector2f cellDimensions{ 0,0 };
	};
}