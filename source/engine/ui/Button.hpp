#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace pi
{
	namespace ui
	{
		class Button
		{
		public:
			Button(sf::Texture&, const sf::Vector2f&, const sf::Vector2f&);

			void update(sf::RenderWindow&);
			void addCallback(void());
			void click(sf::Event);

		private:
			sf::Sprite sprite;
			sf::Vector2f size;
			std::vector <void(*)()> functions;
		};
	}
}



