#pragma once

#include <queue>
#include <SFML/System/Vector2.hpp>
#include "PathFinder.hpp"

class MoveableObject
{
	std::queue<sf::Vector2f> targets;
public:
	
	void SetTargetTo(sf::Vector2f from, sf::Vector2f to);
	bool IsMoving();
};