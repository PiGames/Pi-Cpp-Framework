#include "Button.hpp"

namespace pi
{
	namespace ui
	{
		// Public

		Button::Button()
		{
			for(auto &i : this->m_Functions)
				i = nullptr;
		}

		void Button::setTexture(sf::Texture& texture)
		{
			this->m_Texture = texture;
			this->m_Sprite.setTexture(this->m_Texture);
		}

		void Button::setPosition(const sf::Vector2f& position)
		{
			this->m_Position = position;
			this->m_Sprite.setPosition(this->m_Position);
		}

		void Button::setSize(const sf::Vector2f& size)
		{
			this->m_Size = size;
			this->m_Sprite.setScale({ this->m_Size.x / this->m_Texture.getSize().x, this->m_Size.y / this->m_Texture.getSize().y });
		}

		void Button::addCallback(void function())
		{
			for (unsigned i = 0; i < this->m_Functions.size(); ++i)
				if (this->m_Functions[i] == nullptr)
				{
					this->m_Functions[i] = function; break;
				}
		}

		void Button::use(sf::Event& event)
		{
			if (this->m_Sprite.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
				for (unsigned i = 0; i < this->m_Functions.size(); ++i)
					if(this->m_Functions[i] != nullptr)
						this->m_Functions[i]();
		}
	}
}