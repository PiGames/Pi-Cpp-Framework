#include "Robot.hpp"

namespace mc
{
	Robot::Robot( std::weak_ptr<sf::Texture> texture, const std::string& name, const sf::Vector2f& pos, float speed, float batteryCap ) :
		pi::MovableObject( texture, name, pos, speed ),
		batteryCapacity( batteryCap ),
		distance( 0 ),
		energy( batteryCapacity )
	{
	}
}
