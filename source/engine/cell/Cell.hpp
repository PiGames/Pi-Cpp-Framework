#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "engine/ecs/GameObject.hpp"
#include "engine/pathfinder/PatfinderAttributes.hpp"
#include "engine/Config.hpp"

namespace pi
{
	class Cell : public sf::Drawable, public pi::GameObject
	{
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	public:
		Cell(int id = 0, sf::Texture *texture = nullptr, sf::Vector2f position = sf::Vector2f(0, 0), sf::Vector2f worldSize = sf::Vector2f(0, 0), bool collideable = false);
	
		//Initialization (on the begining of game process)
		static void Init(sf::Vector2i *uWorldSize, sf::Vector2f *celldimensions);

	private:

		const int ID;

		sf::Sprite object;

		static sf::Vector2i *unitWorldSize;

		static sf::Vector2f *cellDimensions;
	};

}
