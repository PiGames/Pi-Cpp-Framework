#pragma once

#include <queue>
#include <SFML/System/Vector2.hpp>
#include "engine/pathfinder/PathFinder.hpp"

namespace pi
{
	class MovableObject : public MapObject
	{
	public:

		MovableObject(const std::string& name = "<unnamed Entity>", const sf::Vector2f& pos = { 0,0 }, float speed = 1.f);

		//Sets target and use pathfinder
		void setTargetTo(const sf::Vector2f& from, const sf::Vector2f& to);

		//Returns state of moving
		bool canMove();

		//Move object in direction of first target
		void move();
		 
	private:

		std::queue<sf::Vector2f> targets;

		const float moveSpeed;
	};	
}
