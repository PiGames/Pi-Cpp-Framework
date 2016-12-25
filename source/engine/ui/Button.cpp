#include "Button.hpp"

namespace pi
{
	namespace ui
	{
		void Button::setTexture(sf::Texture& texture)
		{
			this->m_Texture = texture;
			this->m_Sprite.setTexture(m_Texture);
		}

		void Button::setPosition(const sf::Vector2f& position)
		{
			this->m_Position = position;
			this->m_Sprite.setPosition(m_Position);
		}

		void Button::setSize(const sf::Vector2f& size)
		{
			this->m_Size = size;
			this->m_Sprite.setScale({ this->m_Size.x / this->m_Texture.getSize().x, this->m_Size.y / this->m_Texture.getSize().y });
		}

		void Button::addCallback(void function())
		{
			this->m_Functions.push_back(function);
		}

		void Button::click(sf::Event event)
		{
			if (this->m_Sprite.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
				for (unsigned i = 0; i < this->m_Functions.size(); ++i)
					this->m_Functions[i]();
		}

		void Button::update(sf::RenderWindow& window)
		{
			window.draw(this->m_Sprite);
		}
	}
}