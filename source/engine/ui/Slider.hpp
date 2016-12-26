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
			void setPosition(const sf::Vector2f&);
			void setSize(const sf::Vector2f&);
			// Get

			void event(sf::Event&);
			virtual void update(sf::RenderWindow&) override;

		private:
			sf::Texture m_SliderTexture, m_RateTexture;
			sf::Sprite m_RateSprite;
			std::array <void(*)(), 8> m_Functions;
			bool m_Enable;
		};
	}
}