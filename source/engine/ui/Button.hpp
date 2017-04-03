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
			Button();
			~Button() = default;

			// VIEW FUNCTIONS START
			// Set button texture
			void SetTexture( const sf::Texture& texture, const sf::Texture& release );
			// Set button position
			void SetPosition( const sf::Vector2f& position );
			// Set button size
			void SetSize( const sf::Vector2f& size );
			// Set button postition and size
			void SetRect( const sf::Vector2f& position, const sf::Vector2f& size );
			// VIEW FUNCTIONS END

			// GET START
			// Get button texture
			const sf::Texture GetTexture() const { return this->texture; }
			// GET END

			// Add calback function for button
			void AddCallback( std::function<void()> function );

		private:
			sf::Texture texture, relaseTexture;
			std::array <std::function<void()>, constants::ui::MAX_CALLBACKS> functions;
			bool isClicked;

			// VIRTUAL FUNCTIONS START
			void use( const sf::Event& event ) override;
			// VIRTUAL FUNCTIONS END
		};
	}
}