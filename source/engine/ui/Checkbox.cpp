#include "Checkbox.hpp"

namespace pi
{
	namespace ui
	{
		// Public

		Checkbox::Checkbox()
		{
			for (auto &i : this->m_FunctionsOff)
				i = nullptr;
			for (auto &i : this->m_FunctionsOn)
				i = nullptr;
			this->m_Enable = false;
		}

		void Checkbox::setTexture(sf::Texture& textureOff, sf::Texture& textureOn)
		{
			this->m_TextureOff = textureOff;
			this->m_TextureOn = textureOn;
			if (!this->m_Enable)
			{
				this->m_Texture = &this->m_TextureOff;
			}
			else if (this->m_Enable)
			{
				this->m_Texture = &this->m_TextureOn;
			}
			this->m_Sprite.setTexture(*this->m_Texture);
		}

		void Checkbox::setEnable(bool enable)
		{
			this->m_Enable = enable;
		}

		void Checkbox::setPosition(const sf::Vector2f& position)
		{
			this->m_Position = position;
			this->m_Sprite.setPosition(this->m_Position);
		}

		void Checkbox::setSize(const sf::Vector2f& size)
		{
			this->m_Size = size;
			this->m_Sprite.setScale({ this->m_Size.x / this->m_Texture->getSize().x, this->m_Size.y / this->m_Texture->getSize().y });
		}

		void Checkbox::addCallbackOn(void function())
		{
			for (unsigned i = 0; i < this->m_FunctionsOn.size(); ++i)
				if (this->m_FunctionsOn[i] == nullptr)
				{
					this->m_FunctionsOn[i] = function; break;
				}
		}

		void Checkbox::addCallbackOff(void function())
		{
			for (unsigned i = 0; i < this->m_FunctionsOff.size(); ++i)
				if (this->m_FunctionsOff[i] == nullptr)
				{
					this->m_FunctionsOff[i] = function; break;
				}
		}

		void Checkbox::use(sf::Event& event)
		{
			if (this->m_Sprite.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
			{
				if (!this->m_Enable)
					this->enable();
				else if (this->m_Enable)
					this->disable();
			}
		}

		// Private

		void Checkbox::enable()
		{
			this->m_Enable = true;
			this->m_Texture = &this->m_TextureOn;
			this->m_Sprite.setTexture(*m_Texture);
			for (unsigned i = 0; i < this->m_FunctionsOn.size(); ++i)
				if (this->m_FunctionsOn[i] != nullptr)
					this->m_FunctionsOn[i]();
		}

		void Checkbox::disable()
		{
			this->m_Enable = false;
			this->m_Texture = &this->m_TextureOff;
			this->m_Sprite.setTexture(*m_Texture);
			for (unsigned i = 0; i < this->m_FunctionsOff.size(); ++i)
				if (this->m_FunctionsOff[i] != nullptr)
					this->m_FunctionsOff[i]();
		}
	}
}