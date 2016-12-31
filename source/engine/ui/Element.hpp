#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <array>
#include <functional>

namespace pi
{
	namespace ui
	{
		class Element
		{
		public:
			// Standart gets
			const sf::Vector2f& getPosition() const { return this->position; }
			const sf::Vector2f& getSize() const { return this->size; }
			// Standart UI functions
			virtual void use(sf::Event&) = 0;
			virtual void update(sf::RenderWindow&);

		protected:
			// Standarts UI
			sf::Sprite sprite;
			sf::Vector2f position, size;
		};
	}
}