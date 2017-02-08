// Created by: Condzi
#pragma once

#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Config.hpp"

namespace pi
{
	// Use it to draw things on screen
	// You can pass sf::Drawable object or vector of sf::Drawable as argument
	class SimpleRenderer final
	{
	public:
		SimpleRenderer() = delete;

		template<class T, enable_if<std::is_base_of<sf::Drawable, T>>...>
		static void draw(sf::RenderTarget& window, const T& object)
		{
			window.draw(object);
		}
	
		template<class T, enable_if<std::is_base_of<sf::Drawable, T>>...>
		static void draw(sf::RenderTarget& window, const std::vector<T>& objects)
		{
			for (auto& obj : objects)
				window.draw(obj);
		}

		// You can check if object is in window bounds and then draw it
		static bool isInWindowBounds(sf::RenderTarget& window, const sf::FloatRect& rect)
		{
			auto& view = window.getView();
			sf::Vector2f offset{ view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2 };

			sf::FloatRect windowBounds{ offset, view.getSize() };

			return windowBounds.intersects(rect);
		}
	};
}