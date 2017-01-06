#include "MapObject.hpp"

namespace pi
{
	MapObject::MapObject(const std::string & name, const sf::Vector2f& pos)
		:position(pos),Entity(name)
	{ 

	}

	sf::Vector2f & MapObject::getPosition()
	{
		return position;
	}

	void MapObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(object, states);
	}

}

