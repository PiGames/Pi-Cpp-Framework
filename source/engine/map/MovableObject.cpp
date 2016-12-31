#include "MovableObject.hpp"

namespace pi
{
	void MovableObject::SetTargetTo(sf::Vector2f from, sf::Vector2f to)
	{
		PathFinder::FillTargetsQueue(from,to,&targets);
	}

	bool MovableObject::IsMoving()
	{
		return !targets.empty();
	}
}
