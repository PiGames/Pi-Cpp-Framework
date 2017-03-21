// Created by: mvxxx
#pragma once

#include <queue>
#include <SFML/System/Vector2.hpp>
#include "engine/pathfinder/PathFinder.hpp"
#include "engine/map/MapManager.hpp"
#include "engine/Logger.hpp"
#include "engine/Math.hpp"
#include "engine/Config.hpp"

namespace pi
{
	//MovableObject class
	//Represents MapObject which is able to move
	class MovableObject : public MapObject
	{
	public:

		MovableObject( std::weak_ptr<sf::Texture> texture, const std::string& name = "<unnamed Entity>", const sf::Vector2f& pos = { 0, 0 }, float speed = 1.f );

		//Returns state of moving
		bool CanMove() const
		{
			return !targets.empty();
		}
		//Sets target and use pathfinder
		void SetTargetTo( const sf::Vector2f& from, const sf::Vector2f& to )
		{
			PathFinder::FillTargetsQueue( from, to, targets );
		}
		//Move object in direction of first target
		//returns false if object isn't moving now
		//returns true if object has done step
		bool Move();
		sf::Vector2f& GetCurrentStep()
		{
			return CurrentStep;
		}

	private:

		bool isMoving;
		std::queue<sf::Vector2f> targets;
		const float moveSpeed;
		sf::Vector2f CurrentStep;

		void ComputeStep();
		//Makes single step
		void makeStep()
		{
			this->position += this->CurrentStep;
		}
		//Checks distance to front target
		bool isNearTarget() const
		{
			return Math::Distance( this->object.getPosition(), this->targets.front() ) < constants::cell::CELL_DIMENSIONS.x;
		}
		//Clears targets' vector and returns last one
		sf::Vector2f clearAndGetLastTarget();
	};
}
