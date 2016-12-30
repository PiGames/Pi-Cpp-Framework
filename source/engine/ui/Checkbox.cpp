#include "Checkbox.hpp"

namespace pi
{
	namespace ui
	{
		// Public

		Checkbox::Checkbox()
		{
			for (auto &i : this->functionsOn)
				i = nullptr;
			for (auto &i : this->functionsOff)
				i = nullptr;
			this->isEnable = false;
		}

		void Checkbox::setTexture(sf::Texture& textureOff, sf::Texture& textureOn)
		{
			this->textureOff = textureOn;
			this->textureOn = textureOff;
			if (!this->isEnable)
			{
				this->texture = &this->textureOff;
			}
			else if (this->isEnable)
			{
				this->texture = &this->textureOn;
			}
			this->sprite.setTexture(*this->texture);
		}

		void Checkbox::setPosition(const sf::Vector2f& position)
		{
			this->position = position;
			this->sprite.setPosition(this->position);
		}

		void Checkbox::setSize(const sf::Vector2f& size)
		{
			this->size = size;
			this->sprite.setScale({ this->size.x / this->texture->getSize().x, this->size.y / this->texture->getSize().y });
		}

		void Checkbox::setRect(const sf::Vector2f& position, const sf::Vector2f& size)
		{
			this->position = position;
			this->size = size;
			this->sprite.setPosition(this->position);
			this->sprite.setScale({ this->size.x / this->texture->getSize().x, this->size.y / this->texture->getSize().y });
		}

		void Checkbox::setEnable(bool enable)
		{
			this->isEnable = enable;
		}

		void Checkbox::addCallbackOn(void function())
		{
			for (unsigned i = 0; i < this->functionsOn.size(); ++i)
				if (!this->functionsOn[i])
				{
					this->functionsOn[i] = function; break;
				}
		}

		void Checkbox::addCallbackOff(void function())
		{
			for (unsigned i = 0; i < this->functionsOff.size(); ++i)
				if (this->functionsOff[i] == nullptr)
				{
					this->functionsOff[i] = function; break;
				}
		}

		void Checkbox::use(sf::Event& event)
		{
			if (this->sprite.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
			{
				if (!this->isEnable)
					this->Enable();
				else if (this->isEnable)
					this->Disable();
			}
		}

		// Private

		void Checkbox::Enable()
		{
			this->isEnable = true;
			this->texture = &this->textureOn;
			this->sprite.setTexture(*texture);
			for (unsigned i = 0; i < this->functionsOn.size(); ++i)
				if (this->functionsOn[i])
					this->functionsOn[i]();
		}

		void Checkbox::Disable()
		{
			this->isEnable = false;
			this->texture = &this->textureOff;
			this->sprite.setTexture(*texture);
			for (unsigned i = 0; i < this->functionsOff.size(); ++i)
				if (this->functionsOff[i])
					this->functionsOff[i]();
		}
	}
}