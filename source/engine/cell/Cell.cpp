#include "Cell.hpp"

namespace pi
{
	sf::Vector2i *Cell::unitWorldSize;
	sf::Vector2f *Cell::cellDimensions;

	Cell::Cell(int id, sf::Texture * texture, const std::string & name, const sf::Vector2f& pos, std::vector<sf::Vector2i> uPos, bool collidableFlag)
		:StaticObject(name,pos,uPos,collidableFlag), ID(id)
	{
		object.setTexture(*texture);
		object.setTextureRect(sf::IntRect(ID*cellDimensions->x, 0, cellDimensions->x, cellDimensions->y));
		object.setOrigin(object.getGlobalBounds().width / 2.0f, object.getGlobalBounds().height / 2.0f);
	}

	void Cell::init(sf::Vector2i * uWorldSize, sf::Vector2f * celldimensions)
	{
		cellDimensions = celldimensions;
		unitWorldSize = uWorldSize;
	}
}
