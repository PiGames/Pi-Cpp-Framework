#include "MovableObject.hpp"

namespace pi
{
	MovableObject::MovableObject( std::weak_ptr<sf::Texture> texture, const std::string& name, const sf::Vector2f& pos, float speed ) :
		MapObject( texture, name, pos ),
		moveSpeed( speed ),
		isMoving( false )
	{

	}

	bool MovableObject::Move()
	{
		if ( !CanMove() )
		{
			Logger::Log( constants::error::movableObject::WRONG_USE_MOVE, Logger::MessageType::Warning, Logger::OutputType::Console );
			return false;
		}

		if ( !isMoving )
			ComputeStep();

		makeStep();

		if ( isNearTarget() )
		{
			targets.pop();
			ComputeStep();
		}

		if ( !isMoving ) isMoving = true;
		if ( targets.empty() )isMoving = false;

		return true;
	}

	void MovableObject::ComputeStep()
	{
		sf::Vector2f direction = targets.front() - this->position;

		float magnitude = std::sqrt( ( direction.x * direction.x ) + ( direction.y + direction.y ) );
		this->CurrentStep = sf::Vector2f( direction.x / magnitude, direction.y / magnitude )*moveSpeed;
	}

	sf::Vector2f MovableObject::clearAndGetLastTarget()
	{
		sf::Vector2f last;
		while ( this->targets.size() > 1 )
			this->targets.pop();

		last = this->targets.front();
		this->targets.pop();

		return last;
	}

}
