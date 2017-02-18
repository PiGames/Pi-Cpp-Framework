#include "Cell.hpp"

namespace pi
{
	Cell::Cell(int id, sf::Texture * texture, const std::string & name, const sf::Vector2f& pos, std::vector<sf::Vector2i> uPos, bool collidableFlag)
		:StaticObject(name, pos, uPos, collidableFlag), ID(id)
	{
		object.setTexture(*texture);
		object.setTextureRect(sf::IntRect(ID*constants::cell::CELL_DIMENSIONS.x, 0, constants::cell::CELL_DIMENSIONS.x, constants::cell::CELL_DIMENSIONS.y));
		object.setOrigin(object.getGlobalBounds().width / 2.0f, object.getGlobalBounds().height / 2.0f);
	}

	uint16_t Cell::getID() const
	{
		return ID;
	}
}
