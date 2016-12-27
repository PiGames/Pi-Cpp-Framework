#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "engine/ecs/GameObject.hpp"
#include "engine/realObject/RealObject.hpp"

namespace pi
{
	class Cell : public sf::Drawable, public pi::GameObject, public pi::RealObject
	{
		const int ID;
		sf::Sprite object;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		static sf::Vector2f dimensions;

	public:
		Cell(int id = 0, sf::Texture *texture = nullptr, sf::Vector2f position = sf::Vector2f(0, 0), sf::Vector2f worldSize = sf::Vector2f(0, 0), bool collideable = false);
	};

}
