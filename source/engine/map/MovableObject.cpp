#include "MovableObject.hpp"

namespace pi
{
	void MovableObject::setTargetTo(const sf::Vector2f& from, const sf::Vector2f& to)
	{
		PathFinder::fillTargetsQueue(from,to,&targets);
	}

	bool MovableObject::isMoving()
	{
		return !targets.empty();
	}
}
