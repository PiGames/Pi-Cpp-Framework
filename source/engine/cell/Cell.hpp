#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "CollideableObject.h"

class Cell : public sf::Drawable, public CollideableObject
{
	const sf::Vector2i unitPosition; // in i|j system
	const int ID;
	sf::Sprite object;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	static sf::Vector2f dimensions;

public:
	Cell(int id,sf::Texture *texture,sf::Vector2f position,sf::Vector2f worldSize,bool collideable);
	
	sf::Vector2i GetUnitPosition();
};
