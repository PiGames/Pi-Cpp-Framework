#include "StaticObject.hpp"

namespace pi
{
	StaticObject::StaticObject( std::weak_ptr<sf::Texture> texture, const std::string& name, const sf::Vector2f& pos, std::vector<sf::Vector2i> uPos, bool collidableFlag )
		:MapObject( texture, name, pos ), CollidableObject( collidableFlag ), unitPosition( uPos )
	{
	}

	StaticObject::~StaticObject()
	{
		//to do (update collision map)
	}
}
