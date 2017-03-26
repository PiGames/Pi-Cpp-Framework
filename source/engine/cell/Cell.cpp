#include "Cell.hpp"

namespace pi
{
	Cell::Cell( uint16_t id, const sf::Vector2f& pos, std::vector<sf::Vector2i> uPos, bool collidableFlag ) :
		ID( id ),
		position( pos ),
		unitPosition( uPos ),
		isCollidable( collidableFlag )
	{}
}
