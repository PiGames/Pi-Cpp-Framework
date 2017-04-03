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
		/*
		===============================================================================
		Created by: Beniamin Gajecki ,,Uriel"
		User Interface(UI) Element class.
		===============================================================================
		*/
		class Element
		{
		public:

			friend class UI;

			// STANDART UI GETS START
			// Return element position
			const sf::Vector2f GetPosition() const
			{
				return this->position;
			}
			// Return element size
			const sf::Vector2f GetSize() const
			{
				return this->size;
			}
			// STANDART UI GETS END

		protected:
			// STANDART UI VARIABLES START
			sf::Sprite sprite;
			sf::Vector2f position, size;
			elementType_t type;
			// STANDART UI VARIABLES END

			// STANDART UI FUNCTIONS START
			// Use element
			virtual void use( const sf::Event& event ) = 0;
			// Update element
			virtual void update( sf::RenderWindow& window );
			// STANDART UI FUNCTIONS END
		};
	}
}