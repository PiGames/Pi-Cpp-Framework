#include "MapObject.hpp"

namespace pi
{
	MapObject::MapObject( std::weak_ptr<sf::Texture> texture, const std::string & name, const sf::Vector2f& pos )
		:position( pos ), Entity( name )
	{
		object.setTexture( *texture.lock().get() );
	}

	void MapObject::SetUnitPosition( const sf::Vector2i& position )
	{
		this->object.setPosition(
			this->position.x*constants::cell::CELL_DIMENSIONS.x,
			this->position.y*constants::cell::CELL_DIMENSIONS.y );
	}
}

