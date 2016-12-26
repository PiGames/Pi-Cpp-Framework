#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.hpp"

class Cell : public sf::Drawable, public pi::GameObject
{
	const int ID;
	sf::Sprite object;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	static sf::Vector2f dimensions;

public:
	Cell(int id,sf::Texture *texture,sf::Vector2f position,sf::Vector2f worldSize,bool collideable);
};
