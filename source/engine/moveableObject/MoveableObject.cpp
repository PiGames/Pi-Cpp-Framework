#include "MoveableObject.hpp"

void MoveableObject::SetTargetTo(sf::Vector2f from, sf::Vector2f to)
{
	PathFinder::FillTargetsQueue(from,to,&targets);
}

bool MoveableObject::IsMoving()
{
	return !targets.empty();
}
