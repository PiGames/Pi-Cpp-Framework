#include "MapObject.hpp"

namespace pi
{
	MapObject::MapObject(const std::string & name, const sf::Vector2f& pos, std::vector<sf::Vector2i> uPos, bool collidableFlag)
		:position(pos),unitPosition(uPos),Entity(name), CollidableObject(collidableFlag)
	{ 

	}

	sf::Vector2f & MapObject::getPosition()
	{
		return position;
	}

	std::vector<sf::Vector2i>& MapObject::getUnitPosition()
	{
		return unitPosition;
	}

	void MapObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(object, states);
	}

}

