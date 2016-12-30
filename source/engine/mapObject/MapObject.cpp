#include "MapObject.hpp"

namespace pi
{
	MapObject::MapObject(const std::string & name, sf::Vector2f pos, std::vector<sf::Vector2i> uPos)
		:position(pos),unitPosition(uPos),Entity(name)
	{ 

	}

	sf::Vector2f & MapObject::GetPosition()
	{
		return position;
	}

	std::vector<sf::Vector2i>& MapObject::GetUnitPosition()
	{
		return unitPosition;
	}

	void MapObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(object, states);
	}

}

