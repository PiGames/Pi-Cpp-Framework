#include "RealObject.hpp"

namespace pi 
{
	RealObject::RealObject(bool collisionFlag, std::vector<sf::Vector2i> unitPos) :collideable(collisionFlag), unitPosition(unitPos)
	{
	}

	bool RealObject::IsCollideable()
	{
		return collideable;
	}

	void RealObject::SetCollideableFlag(bool type)
	{
		collideable = type;
	}

	std::vector<sf::Vector2i> RealObject::GetUnitPosition()
	{
		return unitPosition;
	}

	void RealObject::SetUnitPosition(std::vector<sf::Vector2i> unitPos)
	{
		unitPosition = unitPos;
	}

}
