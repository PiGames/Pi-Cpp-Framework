#include "Robot.hpp"

namespace mc
{
	Robot::Robot(const std::string & name, const sf::Vector2f & pos, const float& speed, const float& batteryCap)
		:pi::MapObject(name,pos), pi::MovableObject(speed), batteryCapacity(batteryCap)
	{
		energy = batteryCapacity;
	}
}
