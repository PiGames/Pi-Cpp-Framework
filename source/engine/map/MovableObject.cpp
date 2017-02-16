#include "MovableObject.hpp"

namespace pi
{
	MovableObject::MovableObject(const std::string& name, const sf::Vector2f& pos , float speed ) :
		MapObject(name,pos),
		moveSpeed(speed),
		isMoving(false)
	{

	}

	void MovableObject::setTargetTo(const sf::Vector2f& from, const sf::Vector2f& to)
	{
		PathFinder::FillTargetsQueue(from, to, &targets);
	}

	bool MovableObject::canMove()
	{
		return !targets.empty();
	}

	bool MovableObject::move()
	{
		if (!canMove())
		{
			Logger::Log(constants::error::movableObject::WRONG_USE_MOVE, Logger::MessageType::Warning, Logger::OutputType::Console);
			return false;
		}

		if (!isMoving) 
			ComputeStep();

		makeStep();

		if (isNearTarget())
		{
			targets.pop();
			ComputeStep();
		}

		if (!isMoving) isMoving = true;
		if (targets.empty())isMoving = false;

		return true;
	}

	sf::Vector2f& MovableObject::getCurrentStep()
	{
		return CurrentStep;
	}

	void MovableObject::ComputeStep()
	{
		sf::Vector2f direction = targets.front() - this->position;

		float magnitude = std::sqrt((direction.x * direction.x) + (direction.y + direction.y));
		CurrentStep = sf::Vector2f(direction.x / magnitude, direction.y / magnitude)*moveSpeed;
	}

	void MovableObject::makeStep()
	{
		this->position += CurrentStep;
	}

	bool MovableObject::isNearTarget()
	{
		return Math::Distance(object.getPosition(), targets.front()) < constants::cell::CELL_DIMENSIONS.x;
	}

	sf::Vector2f MovableObject::clearAndGetLastTarget()
	{
		sf::Vector2f last;
		while (targets.size() > 1)targets.pop();

		last = targets.front();
		targets.pop();
		
		return last;
	}

}
