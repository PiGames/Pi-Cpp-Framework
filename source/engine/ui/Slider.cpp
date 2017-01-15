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
			this->checkingInRealMode = false;
			this->scale = { 0.2f, 1.2f };
			this->realTime = 0;
			this->delayTime = 40.f;
			this->type = ElementType::slider;
		}

		void Slider::setTexture(const sf::Texture& sliderTexture, const sf::Texture& rateTexture)
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

		void Slider::addCallback(std::function<void(Slider*)> function)
		{
			for (auto &i : this->functions)
				if (!i)
				{
					i = function; break;
				}
		}

		void Slider::setCheckingInRealMode(const bool isEnable)
		{
			this->checkingInRealMode = isEnable;
		}

		void Slider::setDelayTime(const float time)
		{
			this->delayTime = time;
		}

		// Virtual methods

		void Slider::use(sf::Event& event)
		{
			if (event.type == sf::Event::MouseMoved)
			{
				if (this->isSelected)
				{
					if (event.mouseMove.x != this->ratePosition.x)
					{
						if (event.mouseMove.x >= this->position.x + this->size.x - (this->rateSize.x / 2))
							this->ratePosition.x = this->position.x + this->size.x - this->rateSize.x;
						else if (event.mouseMove.x <= this->position.x + (this->rateSize.x / 2))
							this->ratePosition.x = this->position.x;
						else
							this->ratePosition.x = event.mouseMove.x - (this->rateSize.x / 2);

						this->rateSprite.setPosition(this->ratePosition);

						// If checkingInRealMode - true
						if (this->checkingInRealMode)
						{
							if (this->realTime >= this->delayTime)
							{
								for (auto &i : this->functions)
									if (i)
										i(this);
								this->realTime = 0;
							}
							else
								this->realTime++;
						}
					}
				}
			}
			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				if (this->rateSprite.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
					this->isSelected = true;
			}
			else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				if (this->isSelected)
				{
					this->isSelected = false;
					// If checkingInRealMode - false
					if (!this->checkingInRealMode)
						for (auto &i : this->functions)
							if (i)
								i(this);
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