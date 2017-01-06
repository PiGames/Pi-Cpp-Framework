#include "Button.hpp"

namespace pi
{
	namespace ui
	{
		// Public

		Button::Button()
		{
			this->functions.fill(nullptr);
		}

		void Button::setTexture(sf::Texture& texture)
		{
			this->texture = texture;
			this->sprite.setTexture(this->texture);
		}

		void Button::setPosition(const sf::Vector2f& position)
		{
			this->position = position;
			this->sprite.setPosition(this->position);
		}

		void Button::setSize(const sf::Vector2f& size)
		{
			this->size = size;
			this->sprite.setScale({ this->size.x / this->texture.getSize().x, this->size.y / this->texture.getSize().y });
		}

		void Button::setRect(const sf::Vector2f& position, const sf::Vector2f& size)
		{
			this->position = position;
			this->size = size;
			this->sprite.setPosition(this->position);
			this->sprite.setScale({ this->size.x / this->texture.getSize().x, this->size.y / this->texture.getSize().y });
		}

		void Button::addCallback(std::function<void()> function)
		{
			for (unsigned i = 0; i < this->functions.size(); ++i)
				if (!this->functions[i])
				{
					this->functions[i] = function; break;
				}
		}

		void Button::use(sf::Event& event)
		{
			if (this->sprite.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
				for (unsigned i = 0; i < this->functions.size(); ++i)
					if(this->functions[i])
						this->functions[i]();
		}
	}
}