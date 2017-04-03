#include "UI.hpp"

namespace pi
{
	namespace ui
	{
		// Public

		UI::UI()
		{
			this->elementArrayLength = 0;
		}

		UI::UI( sf::RenderWindow& window )
		{
			this->window = &window;
			this->elementArrayLength = 0;
		}

		// Button methods

		void UI::UseButtons( sf::Event& event )
		{
			for ( auto &i : this->elements )
			{
				if ( i )
				{
					if ( i->type == elementType_t::BUTTON )
					{
						i->use( event );
					}
				}
			}
		}

		void UI::UpdateButtons( sf::RenderWindow& window )
		{
			for ( auto &i : this->elements )
			{
				if ( i )
				{
					if ( i->type == elementType_t::BUTTON )
					{
						i->update( window );
					}
				}
			}
		}

		// Checkbox methods

		void UI::UseCheckboxes( sf::Event& event )
		{
			for ( auto &i : this->elements )
			{
				if ( i )
				{
					if ( i->type == elementType_t::CHECKBOX )
					{
						i->use( event );
					}
				}
			}
		}

		void UI::UpdateCheckboxes( sf::RenderWindow& window )
		{
			for ( auto &i : this->elements )
			{
				if ( i )
				{
					if ( i->type == elementType_t::CHECKBOX )
					{
						i->update( window );
					}
				}
			}
		}

		// Slider methods

		void UI::UseSliders( sf::Event& event )
		{
			for ( auto &i : this->elements )
			{
				if ( i )
				{
					if ( i->type == elementType_t::SLIDER )
					{
						i->use( event );
					}
				}
			}
		}

		void UI::UpdateSliders( sf::RenderWindow& window )
		{
			for ( auto &i : this->elements )
			{
				if ( i )
				{
					if ( i->type == elementType_t::SLIDER )
					{
						i->update( window );
					}
				}
			}
		}

		// List methods

		void UI::UseLists( sf::Event& event )
		{
			for ( auto &i : this->elements )
			{
				if ( i )
				{
					if ( i->type == elementType_t::LIST )
					{
						i->use( event );
					}
				}
			}
		}

		void UI::UpdateLists( sf::RenderWindow& window )
		{
			for ( auto &i : this->elements )
			{
				if ( i )
				{
					if ( i->type == elementType_t::LIST )
					{
						i->update( window );
					}
				}
			}
		}

	}
}