#include "Cell.hpp"
#include <iostream>
namespace pi
{
	Cell::Cell( int identifier, const sf::Vector2i& unitPosition )
		: id( identifier / constants::cell::ROTATION_MODES )
	{
		this->object.setOrigin( constants::cell::CELL_DIMENSIONS.x / 2.0f, constants::cell::CELL_DIMENSIONS.y / 2.0f );
		this->object.setPosition( unitPosition.x * constants::cell::CELL_DIMENSIONS.x + (constants::cell::CELL_DIMENSIONS.x / 2.0f), unitPosition.y * constants::cell::CELL_DIMENSIONS.y + (constants::cell::CELL_DIMENSIONS.y / 2.0f) );
		this->object.setRotation( ( this->id % constants::cell::ROTATION_MODES + 2 ) * constants::cell::STRAIGHT_ANGLE );
	}
}
