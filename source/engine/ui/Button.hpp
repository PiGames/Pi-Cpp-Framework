#pragma once

#include "Element.hpp"

#include <array>
#include <algorithm>

namespace pi
{
	namespace ui
	{
		class Button final : public pi::ui::Element
		{
		public:
			Button();
			~Button() = default;
			
			// Set
			void setTexture(sf::Texture&);
			void setPosition(const sf::Vector2f&);
			void setSize(const sf::Vector2f&);
			void setRect(const sf::Vector2f&, const sf::Vector2f&);
			// Get
			sf::Texture getTexture() const { return this->texture; }

			void addCallback(void());

			virtual void use(sf::Event& event) override;

		private:
			sf::Texture texture;
			std::array <void(*)(), 8> functions;
		};
	}
}