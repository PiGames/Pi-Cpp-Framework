#include "Slider.hpp"



namespace pi
{
	namespace ui
	{
		// Public

		Slider::Slider()
		{
			for (auto &i : this->m_Functions)
				i = nullptr;
			this->m_Enable = false;			
		}

		void Slider::setTexture(sf::Texture& sliderTexture, sf::Texture& rateTexture)
		{
			this->m_SliderTexture = sliderTexture;
			this->m_RateTexture = rateTexture;
			this->m_Sprite.setTexture(this->m_SliderTexture);
			this->m_RateSprite.setTexture(this->m_RateTexture);
		}

		void Slider::setRect(const sf::Vector2f& position, const sf::Vector2f& size)
		{
			this->m_Position = position;
			this->m_Size = size;
			// Set scale for slider and rate
			this->m_Sprite.setScale({ this->m_Size.x / this->m_SliderTexture.getSize().x, this->m_Size.y / this->m_SliderTexture.getSize().y });
			this->m_RateSprite.setScale({ this->m_Size.x / static_cast<float>(this->m_RateTexture.getSize().x) * 0.2f, this->m_Size.y / static_cast<float>(this->m_RateTexture.getSize().y) * 1.2f });

			// Multiplied scale with texture size
			this->m_RateSize = { (this->m_Size.x / static_cast<float>(this->m_RateTexture.getSize().x) * 0.2f) * static_cast<float>(this->m_RateTexture.getSize().x),
			(this->m_Size.y / static_cast<float>(this->m_RateTexture.getSize().y) * 1.2f) * static_cast<float>(this->m_RateTexture.getSize().y) };

			
			// Set position for slider and rate
			this->m_Sprite.setPosition(this->m_Position);
			this->m_RateSprite.setPosition({ this->m_Position.x + (this->m_Size.x / 2) - (this->m_RateSize.x / 2), this->m_Position.y + (this->m_Size.y / 2) - (this->m_RateSize.y /2) });
		}

		void Slider::use(sf::Event& event)
		{

		}

		void Slider::update(sf::RenderWindow& window)
		{
			window.draw(this->m_Sprite);
			window.draw(this->m_RateSprite);
		}
	}
}