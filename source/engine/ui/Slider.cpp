#include "Slider.hpp"



namespace pi
{
	namespace ui
	{
		// Public

		Slider::Slider()
		{
			this->functions.fill(nullptr);

			this->isSelected = false;
			this->scale = { 0.2f, 1.2f };
		}

		void Slider::setTexture(sf::Texture& sliderTexture, sf::Texture& rateTexture)
		{
			this->sliderTexture = sliderTexture;
			this->rateTexture = rateTexture;
			this->sprite.setTexture(this->sliderTexture);
			this->rateSprite.setTexture(this->rateTexture);
		}
		
		void Slider::setScale(const sf::Vector2f& scale)
		{
			this->scale = scale;
		}

		void Slider::setRect(const sf::Vector2f& position, const sf::Vector2f& size)
		{
			this->position = position;
			this->size = size;
			// Set scale for slider and rate
			this->sprite.setScale({ this->size.x / this->sliderTexture.getSize().x, this->size.y / this->sliderTexture.getSize().y });
			this->rateSprite.setScale({ this->size.x / static_cast<float>(this->rateTexture.getSize().x) * scale.x, this->size.y / static_cast<float>(this->rateTexture.getSize().y) * scale.y });

			// Multiplied scale with texture size
			this->rateSize = { (this->size.x / static_cast<float>(this->rateTexture.getSize().x) * scale.x) * static_cast<float>(this->rateTexture.getSize().x),
			(this->size.y / static_cast<float>(this->rateTexture.getSize().y) * scale.y) * static_cast<float>(this->rateTexture.getSize().y) };

			
			// Set position for slider and rate
			this->sprite.setPosition(this->position);
			this->ratePosition = { this->position.x + (this->size.x / 2) - (this->rateSize.x / 2), this->position.y + (this->size.y / 2) - (this->rateSize.y / 2) };
			this->rateSprite.setPosition(this->ratePosition);
		}

		void Slider::addCallback(void function(Slider*))
		{
			for (unsigned i = 0; i < this->functions.size(); ++i)
				if (!this->functions[i])
				{
					this->functions[i] = function; break;
				}
		}

		void Slider::selected(sf::Event& event)
		{
			if (this->rateSprite.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
			{
				this->isSelected = true;
			}
		}

		void Slider::callback()
		{
			for (unsigned i = 0; i < this->functions.size(); ++i)
				if (this->functions[i])
					this->functions[i](this);
		}

		void Slider::released()
		{
			this->isSelected = false;
		}

		// Virtual methods

		void Slider::use(sf::Event& event)
		{
			if (this->isSelected)
			{
				if (event.mouseMove.x != this->ratePosition.x)
				{
					if (event.mouseMove.x >= position.x + size.x - (rateSize.x / 2))
						ratePosition.x = position.x + size.x - rateSize.x;
					else if (event.mouseMove.x <= position.x + (rateSize.x / 2))
						ratePosition.x = position.x;
					else
						ratePosition.x = event.mouseMove.x - (rateSize.x / 2);

					rateSprite.setPosition(ratePosition);
				}
			}
		}

		void Slider::update(sf::RenderWindow& window)
		{
			window.draw(this->sprite);
			window.draw(this->rateSprite);
		}
	}
}