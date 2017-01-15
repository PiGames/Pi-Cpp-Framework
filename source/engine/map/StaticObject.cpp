#include "StaticObject.hpp"

namespace pi
{
	StaticObject::StaticObject(const std::string& name, const sf::Vector2f& pos, std::vector<sf::Vector2i> uPos, bool collidableFlag)
		:MapObject(name, pos), CollidableObject(collidableFlag), unitPosition(uPos)
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
