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
		List class
		===============================================================================
		*/
		class List final : public Element
		{
		public:
			List();
			~List() = default;

			List& operator =( const List& ) = delete;
			List( const List& element ) = delete;

			// VIEW FUNCTIONS START
			// Set list texture
			void SetTexture( const sf::Texture& texture );
			// Set list position
			void SetPosition( const sf::Vector2f& position );
			// Set list size
			void SetSize( const sf::Vector2f& size );
			// Set list position and size
			void SetRect( const sf::Vector2f& position, const sf::Vector2f& size );
			// Set description shape and her delay time
			void SetDescription( const sf::RectangleShape& shape, float time );
			// VIEW FUNCTIONS END

			// GET START
			// Get list head texture
			const sf::Texture GetTexture() const { return this->texture; }
			// Get list Length
			const size_t GetListLength() const { return this->listLength; }
			// Get list open - yes or no
			const bool GetOpen() const { return this->isOpen; }
			// GET END

			// Add list element, his function, texture and text for description
			void AddElement( std::function<void()> function, sf::Texture& texture, sf::Text& text );

		private:
			sf::Texture texture;
			sf::RectangleShape descriptionShape;
			sf::Vector2i mousePosition;
			size_t listLength, descriptionLength;
			float realTime, delayTime;
			bool isOpen, drawDescription, cursorOnList;

			struct listStruct_t
			{
				std::function<void()> function;
				sf::Texture* texture;
				sf::Sprite sprite;
				sf::Text text;
				sf::Vector2f position;
			};
			std::array <std::unique_ptr<listStruct_t>, constants::ui::MAX_UIELEMENTS> list;

			void use( const sf::Event& event ) override;
			void update( sf::RenderWindow& window ) override;
		};
	}
}