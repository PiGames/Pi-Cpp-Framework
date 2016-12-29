#include "Cell.hpp"

namespace pi
{
	void Cell::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(object, states);
	}

	Cell::Cell(int id, sf::Texture *texture, sf::Vector2f position, sf::Vector2f worldSize, bool collideable)
		:ID(id)
	{
		object.setTexture(*texture);
		object.setTextureRect(sf::IntRect(ID*MapManager::GetCellDimensions().x, 0, MapManager::GetCellDimensions().x, MapManager::GetCellDimensions().y));
		object.setOrigin(object.getGlobalBounds().width / 2.0f, object.getGlobalBounds().height / 2.0f);

		this->addComponent(PathfinderAttributes(*this));
		this->getComponent<PathfinderAttributes>()->addFlag(constants::pathfinder::flagNames::COLLIDABLE, false);
	}
}
