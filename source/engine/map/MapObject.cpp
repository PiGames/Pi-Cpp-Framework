#include "MapObject.hpp"

namespace pi
{
	MapObject::MapObject( std::weak_ptr<sf::Texture> texture, const std::string & name, const sf::Vector2f& pos )
		:position( pos ), Entity( name )
	{
		object.setTexture( *texture.lock() );
	}

}

