/*
===============================================================================
Created by: Beniamin Gajecki ,,Uriel"
User Interface(UI) Element class.
===============================================================================
*/
#pragma once

#include <memory>
#include <array>
#include <functional>

#include <SFML/Graphics.hpp>

namespace pi
{
	namespace ui
	{
		enum elementType_t
		{
			BUTTON,
			CHECKBOX,
			SLIDER,
			LIST
		};

		class Element
		{
		public:

			friend class UI;

			// STANDART UI GETS START
			// Return element position
			const sf::Vector2f getPosition( ) const { return this->position; }
			// Return element size
			const sf::Vector2f getSize( ) const { return this->size; }
			// STANDART UI GETS END

		protected:
			// STANDART UI FUNCTIONS START
			// Use element
			virtual void use( sf::Event& ) = 0;
			// Update element
			virtual void update( sf::RenderWindow& );
			// STANDART UI FUNCTIONS END

			// STANDART UI VARIABLES START
			sf::Sprite sprite;
			sf::Vector2f position, size;
			elementType_t type;
			// STANDART UI VARIABLES END
		};
	}
}