#pragma once

#include <queue>
#include <SFML/System/Vector2.hpp>
#include "engine/pathfinder/PathFinder.hpp"
#include "engine/map/MapManager.hpp"
#include "engine/Logger.hpp"
#include "engine/Math.hpp"

namespace pi
{
	class MovableObject : public MapObject
	{
	public:

		MovableObject(const std::string& name = "<unnamed Entity>", const sf::Vector2f& pos = { 0,0 }, float speed = 1.f);

		//Returns state of moving
		bool canMove();

		//Sets target and use pathfinder
		void setTargetTo(const sf::Vector2f& from, const sf::Vector2f& to);

		//Move object in direction of first target
		//returns false if object isn't moving now
		//returns true if object has done step
		bool move();

		sf::Vector2f& getCurrentStep();
		 
	private:

		void ComputeStep();

		//Makes single step
		void makeStep();

		//Checks distance to front target
		bool isNearTarget();

		std::queue<sf::Vector2f> targets;

		const float moveSpeed;

		sf::Vector2f CurrentStep;
	};	
}
