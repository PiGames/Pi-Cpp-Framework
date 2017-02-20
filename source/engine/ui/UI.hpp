/*
===============================================================================
Created by: Beniamin Gajecki ,,Uriel"
User Interface(UI) class.
===============================================================================
*/
#pragma once

#include "Element.hpp"
#include "Button.hpp"
#include "Checkbox.hpp"
#include "Slider.hpp"
#include "List.hpp"
#include "engine/Config.hpp"

namespace pi
{
	namespace ui
	{
		class UI final
		{
		public:
			UI( );
			UI( sf::RenderWindow& );
			~UI( ) = default;

			UI& operator =( const UI& ) = delete;
			UI( const UI& ) = delete;

			// Set window handle for UI
			void setWindow( sf::RenderWindow& );
			
			// Get number procent
			const float getPercent( float procent, float number ) const { return number * procent / 100; }
			// Get window size - MUST USED setWindow or special constructor
			const sf::Vector2u getWindowSize( ) const { return this->window->getSize( ); }

			// Add element to base
			template<typename T>
			T* add( )
			{
				for( auto &i : this->elements )
				{
					if( !i )
					{
						i.reset( new T );
						return dynamic_cast<T*>( i.get( ) );
						break;
					}
				}
				return nullptr;
			}

			// Buttons section start
			void useButtons( sf::Event& );
			void updateButtons( sf::RenderWindow& );
			// Buttons section end

			// Chechbox section start
			void useCheckboxs( sf::Event& );
			void updateCheckboxs( sf::RenderWindow& );
			// Chechbox section end

			// Slider section start
			void useSliders( sf::Event& );
			void updateSliders( sf::RenderWindow& );
			// Slider section end

			// List section start
			void useLists( sf::Event& );
			void updateLists( sf::RenderWindow& );
			// List section end

		private:
			sf::RenderWindow* window;
			unsigned elementArrayLenght;

			std::array <std::unique_ptr<Element>, constants::ui::MAX_UIELEMENTS * constants::ui::NUMBER_OF_UI_ELEMENTS> elements;
		};
	}
}