#pragma once

#include "Element.hpp"
#include "engine/Config.hpp"

namespace pi
{
	namespace ui
	{
		class Slider final : public Element
		{
		public:
			Slider();
			~Slider() = default;

			// VIEV FUNCTIONS START
			// Set slider and rate texture
			void setTexture(const sf::Texture&, const sf::Texture&);
			// Set scale slider and rate
			void setScale(const sf::Vector2f&);
			// Set position and size
			void setRect(const sf::Vector2f&, const sf::Vector2f&);
			// VIEV FUNCTIONS END

			// GET START
			// If user click rate and not relase mouse button 
			const bool getSelected() const { return this->isSelected; }
			// GET END

			// FUNCTIONS FOR FUNCTIONS IN ARRAY START
			float scalePositionOfRate() const { return (this->ratePosition.x - this->position.x) / (this->size.x - this->rateSize.x); }
			float scalePositionOfRateToReal(float number) const { return (this->ratePosition.x - this->position.x) / (this->size.x - this->rateSize.x) * number; }
			// FUNCTIONS FOR FUNCTIONS IN ARRAY END

			// Add calback function for slider
			void addCallback(std::function<void(Slider*)>);
			// Set checking whether rate is selected and use callback
			void setCheckingInRealMode(const bool);
			// Set delay time for checkingInRealMode
			void setDelayTime(const float);

		private:
			sf::Texture sliderTexture, rateTexture;
			sf::Sprite rateSprite;
			sf::Vector2f ratePosition, rateSize, scale;
			std::array <std::function<void(Slider*)>, constants::ui::MAX_CALLBACKS> functions;
			float realTime, delayTime;
			bool isSelected, checkingInRealMode;

			// VIRTUAL FUNCTIONS START
			void use(sf::Event&) final;
			void update(sf::RenderWindow&) final;
			// VIRTUAL FUNCTIONS START
		};
	}
}