#include "Cell.hpp"

namespace pi
{
	sf::Vector2f Cell::dimensions;

	void Cell::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(object, states);
	}

	Cell::Cell(int id, sf::Texture *texture, sf::Vector2f position, sf::Vector2f worldSize, bool collideable)
		:ID(id)
	{
		object.setTexture(*texture);
		object.setTextureRect(sf::IntRect(ID*Cell::dimensions.x, 0, Cell::dimensions.x, Cell::dimensions.y));
		object.setOrigin(object.getGlobalBounds().width / 2.0f, object.getGlobalBounds().height / 2.0f);
	}

}
