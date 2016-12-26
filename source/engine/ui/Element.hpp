#pragma once

#include <SFML/Graphics.hpp>


namespace pi
{
	namespace ui
	{
		class Element
		{
		public:
			// Standart gets
			const sf::Vector2f getPosition() const { return this->m_Position; }
			const sf::Vector2f getSize() const { return this->m_Size; }
			// Standart UI functions
			virtual void use(sf::Event&) = 0;
			virtual void update(sf::RenderWindow&);
			// Standarts UI
			sf::Sprite m_Sprite;
			sf::Vector2f m_Position, m_Size;
		};
	}
}