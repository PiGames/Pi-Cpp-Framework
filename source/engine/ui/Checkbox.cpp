#include "Checkbox.hpp"

namespace pi
{
	namespace ui
	{
		void Checkbox::setTexture(sf::Texture& textureOff, sf::Texture& textureOn)
		{
			this->m_TextureOff = textureOff;
			this->m_TextureOn = textureOn;
			this->m_Texture = &this->m_TextureOff;
			this->m_Sprite.setTexture(*m_Texture);
		}

		void Checkbox::setPosition(const sf::Vector2f& position)
		{
			this->m_Position = position;
			this->m_Sprite.setPosition(m_Position);
		}

		void Checkbox::setSize(const sf::Vector2f& size)
		{
			this->m_Size = size;
			this->m_Sprite.setScale({ this->m_Size.x / this->m_Texture->getSize().x, this->m_Size.y / this->m_Texture->getSize().y });
		}

		void Checkbox::addCallbackOff(void function())
		{
			this->m_FunctionsOff.push_back(function);
		}

		void Checkbox::addCallbackOn(void function())
		{
			this->m_FunctionsOn.push_back(function);
		}

		void Checkbox::use(sf::Event& event)
		{
			if (this->m_Sprite.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				if (!this->m_Enable)
					this->enable();
				else if (this->m_Enable)
					this->disable();
			}
		}

		void Checkbox::update(sf::RenderWindow& window)
		{
			window.draw(this->m_Sprite);
		}

		void Checkbox::enable()
		{
			this->m_Enable = true;
			this->m_Texture = &this->m_TextureOn;
			this->m_Sprite.setTexture(*m_Texture);
			for (unsigned i = 0; i < this->m_FunctionsOn.size(); ++i)
				this->m_FunctionsOn[i]();
		}

		void Checkbox::disable()
		{
			this->m_Enable = false;
			this->m_Texture = &this->m_TextureOff;
			this->m_Sprite.setTexture(*m_Texture);
			for (unsigned i = 0; i < this->m_FunctionsOff.size(); ++i)
				this->m_FunctionsOff[i]();
		}
	}
}