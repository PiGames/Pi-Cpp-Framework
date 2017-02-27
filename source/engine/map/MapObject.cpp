#include "MapObject.hpp"

namespace pi
{
	MapObject::MapObject( const std::string & name, const sf::Vector2f& pos )
		:position( pos ), Entity( name )
	{

	}

	void MapObject::SetPosition( const sf::Vector2i& position )
	{
		this->object.setPosition(
			this->position.x*constants::cell::CELL_DIMENSIONS.x,
			this->position.y*constants::cell::CELL_DIMENSIONS.y );
	}
}

