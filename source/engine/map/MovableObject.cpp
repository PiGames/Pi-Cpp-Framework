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
		PathFinder::fillTargetsQueue(from, to, &targets);
	}

	bool MovableObject::canMove()
	{
		return !targets.empty();
	}

	bool MovableObject::move()
	{
		if (!canMove())
		{
			Logger::log(constants::error::movableObject::WRONG_USE_MOVE, Logger::MessageType::Warning, Logger::OutputType::Console);
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
		return Math::distance(object.getPosition(), targets.front()) < MapManager::getCellDimensions().x;
	}
}
