#pragma once

#include "Element.hpp"

#include <array>

namespace pi
{
	namespace ui
	{
		class Slider final : public Element
		{
		public:
			Slider();
			~Slider() = default;

			// Set
			void setTexture(sf::Texture&, sf::Texture&);
			void setScale(const sf::Vector2f&);
			void setRect(const sf::Vector2f&, const sf::Vector2f&);
			// Get
			const bool getEnable() const { return this->enable; }
			
			// section Functions for functions in array start
			float scalePositionOfRate() const { return (this->ratePosition.x - this->position.x) / (this->size.x - this->rateSize.x); }
			float scalePositionOfRateToReal(float number) const { return (this->ratePosition.x - this->position.x) / (this->size.x - this->rateSize.x) * number; }
			// section Functions for functions in array end
			
			void addCallback(void(Slider*));

			void selected(sf::Event&);
			void released();

			virtual void use(sf::Event&) override;
			virtual void update(sf::RenderWindow&) override;

		private:
			sf::Texture sliderTexture, rateTexture;
			sf::Sprite rateSprite;
			sf::Vector2f ratePosition, rateSize, scale;
			std::array <void(*)(Slider*), 8 > functions;
			bool enable;
		};
	}
}