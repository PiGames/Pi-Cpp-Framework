#pragma once

#include <queue>
#include <SFML/System/Vector2.hpp>
#include "engine/pathfinder/PathFinder.hpp"

namespace pi
{
	class MoveableObject
	{
	public:
		//Sets target and use pathfinder
		void SetTargetTo(sf::Vector2f from, sf::Vector2f to);

		//Returns state of moving
		bool IsMoving();
		 
	private:

		std::queue<sf::Vector2f> targets;
	};	
}
