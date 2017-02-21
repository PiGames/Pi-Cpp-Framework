#pragma once

#include "Element.hpp"
#include "engine/Config.hpp"

namespace pi
{
	namespace ui
	{
/*
===============================================================================
Created by: Beniamin Gajecki ,,Uriel"
Button class.
===============================================================================
*/
		class Button final : public Element
		{
		public:
			Button( );
			~Button( ) = default;
			
			// VIEW FUNCTIONS START
			// Set button texture
			void setTexture( const sf::Texture&, const sf::Texture& );
			// Set button position
			void setPosition( const sf::Vector2f& );
			// Set button size
			void setSize( const sf::Vector2f& );
			// Set button postition and size
			void setRect( const sf::Vector2f&, const sf::Vector2f& );
			// VIEW FUNCTIONS END

			// GET START
			// Get button texture
			const sf::Texture getTexture( ) const { return this->texture; }
			// GET END

			// Add calback function for button
			void addCallback( std::function<void( )> );

		private:
			sf::Texture texture, relaseTexture;
			std::array <std::function<void( )>, constants::ui::MAX_CALLBACKS> functions;
			bool isClicked;

			// VIRTUAL FUNCTIONS START
			void use( sf::Event& event ) final;
			// VIRTUAL FUNCTIONS END
		};
	}
}