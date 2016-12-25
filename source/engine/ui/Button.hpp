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
			Button() = default;
			~Button() = default;

			// Set
			void setTexture(sf::Texture&);
			void setPosition(const sf::Vector2f&);
			void setSize(const sf::Vector2f&);
			// Get
			sf::Texture getTexture() { return this->m_Texture; }
			const sf::Vector2f getPosition() const { return this->m_Position; }
			const sf::Vector2f getSize() const { return this->m_Size; }

			void addCallback(void());
			void click(sf::Event);
			void update(sf::RenderWindow&);

		private:
			sf::Texture m_Texture;
			sf::Sprite m_Sprite;
			sf::Vector2f m_Position, m_Size;
			std::vector <void(*)()> m_Functions;
		};
	}
}