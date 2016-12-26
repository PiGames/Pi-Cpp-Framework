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

		void Slider::setPosition(const sf::Vector2f& position)
		{
			this->m_Position = position;
			this->m_Sprite.setPosition(this->m_Position);
			this->m_RateSprite.setPosition({ this->m_Position.x + (this->m_SliderTexture.getSize().x / 2) - (this->m_RateTexture.getSize().x / 2), this->m_Position.y });
		}

		void Slider::setSize(const sf::Vector2f& size)
		{
			this->m_Size = size;
			this->m_Sprite.setScale({ this->m_Size.x / this->m_SliderTexture.getSize().x, this->m_Size.y / this->m_SliderTexture.getSize().y });
			this->m_RateSprite.setScale({ this->m_Size.x / this->m_SliderTexture.getSize().x * 0.2, this->m_Size.y / this->m_SliderTexture.getSize().y * 0.2});
		}

		void Slider::event(sf::Event& event)
		{

		}

		void Slider::update(sf::RenderWindow& window)
		{
			window.draw(this->m_Sprite);
			window.draw(this->m_RateSprite);
		}
	}
}