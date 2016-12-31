#pragma once

#include "Element.hpp"
#include "engine/Config.hpp"

namespace pi
{
	namespace ui
	{
		class Button final : public Element
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

			void addCallback(std::function<void()>);

			virtual void use(sf::Event& event) final override;

		private:
			sf::Texture texture;
			std::array <std::function<void()>, constants::ui::MAX_CALLBACKS> functions;
		};
	}
}