#include "MovableObject.hpp"

namespace pi
{
	MovableObject::MovableObject(const std::string& name, const sf::Vector2f& pos , float speed )
		:MapObject(name,pos),moveSpeed(speed)
	{

	}

	void MovableObject::setTargetTo(const sf::Vector2f& from, const sf::Vector2f& to)
	{
		PathFinder::fillTargetsQueue(from,to,&targets);
	}

	bool MovableObject::canMove()
	{
		return !targets.empty();
	}

	void MovableObject::Move()
	{
	}
}
