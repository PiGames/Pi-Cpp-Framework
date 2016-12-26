#pragma once

#include "Element.hpp"

#include <array>

namespace pi
{
	namespace ui
	{
		class Slider : public pi::ui::Element
		{
		public:
			Slider();
			~Slider() = default;

			// Set
			void setTexture(sf::Texture&, sf::Texture&);
			void setRect(const sf::Vector2f&, const sf::Vector2f&);
			// Get

			virtual void use(sf::Event&) override;
			virtual void update(sf::RenderWindow&) override;

		private:
			sf::Texture m_SliderTexture, m_RateTexture;
			sf::Sprite m_RateSprite;
			sf::Vector2f m_RateSize;
			std::array <void(*)(), 8> m_Functions;
			bool m_Enable;
		};
	}
}