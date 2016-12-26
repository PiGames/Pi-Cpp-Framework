#pragma once

#include "Element.hpp"

#include <array>
#include <algorithm>

namespace pi
{
	namespace ui
	{
		class Button : public pi::ui::Element
		{
		public:
			Button();
			~Button() = default;
			
			// Set
			void setTexture(sf::Texture&);
			void setPosition(const sf::Vector2f&);
			void setSize(const sf::Vector2f&);
			// Get
			sf::Texture getTexture() const { return this->m_Texture; }

			void addCallback(void());

			virtual void use(sf::Event& event) override;

		private:
			sf::Texture m_Texture;
			std::array <void(*)(), 8> m_Functions;
		};
	}
}