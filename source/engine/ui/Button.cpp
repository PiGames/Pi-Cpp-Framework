#include "Button.hpp"


namespace pi
{
	namespace ui
	{
		Button::Button(sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& factors)
			: sprite(texture)
		{
			sprite.setPosition(position);
			size = { factors.x, factors.y };
			sprite.setScale({ size.x / texture.getSize().x, size.y / texture.getSize().y });
		}

		void Button::addCallback(void function())
		{
			functions.push_back(function);
		}

		void Button::click(sf::Event event)
		{
			if (this->sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				for (unsigned i = 0; i < functions.size(); ++i)
					functions[i]();
		}

		void Button::update(sf::RenderWindow& window)
		{
			window.draw(sprite);
		}
	}
}
