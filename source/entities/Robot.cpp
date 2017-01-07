#include "Robot.hpp"

namespace mc
{
	Robot::Robot(const std::string & name, const sf::Vector2f & pos, const float& speed, const float& batteryCap)
		:pi::MovableObject(name,pos,speed), batteryCapacity(batteryCap), distance(0), energy(batteryCapacity)
	{
	}
}
