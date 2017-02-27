#pragma once

#include "engine/Config.hpp"

#include "Element.hpp"
#include "Button.hpp"
#include "Checkbox.hpp"
#include "Slider.hpp"
#include "List.hpp"

namespace pi
{
	namespace ui
	{
		/*
		===============================================================================
		Created by: Beniamin Gajecki ,,Uriel"
		User Interface(UI) class.
		===============================================================================
		*/
		class UI final
		{
		public:
			UI();
			UI( sf::RenderWindow& );
			~UI() = default;

			UI& operator =( const UI& ) = delete;
			UI( const UI& ) = delete;

			// Set window handle for UI
			void SetWindow( sf::RenderWindow& window )
			{
				this->window = &window;
			}

			// Get number procent
			const float GetPercent( float percent, float number ) const { return number * percent / 100; }
			// Get window size - MUST USED setWindow or special constructor
			const sf::Vector2u GetWindowSize() const { return this->window->getSize(); }

			// Add element to base
			template<typename T>
			T* Add()
			{
				for ( auto &i : this->elements )
				{
					if ( !i )
					{
						i.reset( new T );
						return dynamic_cast<T*>( i.get() );
						break;
					}
				}
				return nullptr;
			}

			// Buttons section start
			void UseButtons( sf::Event& event );
			void UpdateButtons( sf::RenderWindow& window );
			// Buttons section end

			// Chechbox section start
			void UseCheckboxes( sf::Event& event );
			void UpdateCheckboxes( sf::RenderWindow& window );
			// Chechbox section end

			// Slider section start
			void UseSliders( sf::Event& event );
			void UpdateSliders( sf::RenderWindow& window );
			// Slider section end

			// List section start
			void UseLists( sf::Event& event );
			void UpdateLists( sf::RenderWindow& );
			// List section end

		private:
			sf::RenderWindow* window;
			std::size_t elementArrayLength;

			std::array <std::unique_ptr<Element>, constants::ui::MAX_UIELEMENTS * constants::ui::NUMBER_OF_UI_ELEMENTS> elements;
		};
	}
}