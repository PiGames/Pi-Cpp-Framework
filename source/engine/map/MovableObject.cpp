#include "MovableObject.hpp"

namespace pi
{
	void MovableObject::SetTargetTo(const sf::Vector2f& from, const sf::Vector2f& to)
	{
		PathFinder::FillTargetsQueue(from,to,&targets);
	}

	bool MovableObject::IsMoving()
	{
		return !targets.empty();
	}
}
