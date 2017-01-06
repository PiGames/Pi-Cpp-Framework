#include "StaticObject.hpp"

namespace pi
{
	StaticObject::StaticObject(std::vector<sf::Vector2i> uPos, bool collidableFlag)
		:unitPosition(uPos), CollidableObject(collidableFlag)
	{
	}

	StaticObject::~StaticObject()
	{
		//to do (update collision map)
	}

	std::vector<sf::Vector2i>& StaticObject::getUnitPosition()
	{
		return unitPosition;
	}

}
