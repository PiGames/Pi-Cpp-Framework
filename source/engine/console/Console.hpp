#pragma once

#include <memory>
#include <array>
#include <vector>
#include <string>
#include <functional>

#include <SFML/Graphics.hpp>

#include "engine/Config.hpp"

namespace pi
{
	class Console;

	struct command_t
	{
		std::function<void( Console*, command_t* )> function;
		std::string induction;
		std::vector<std::string> args;
	};
	/*
	===============================================================================
	Created by: Beniamin Gajecki ,,Uriel"
	Console class.
	===============================================================================
	*/
	class Console final : public sf::Drawable
	{
	public:
		void Update( sf::RenderWindow& window );
		Console();
		Console( const sf::Vector2u& size );
		~Console() = default;

		Console& operator =( const Console& ) = delete;
		Console( const Console& ) = delete;

		// CONSOLE VIEW FUNCTIONS START
		// Set window handle
		// YOU MUST USE IT IF YOU DIDN'T USE THIS CONSTRUCTOR -> Console( sf::RenderWindow& );
		void SetWindowSize( const sf::Vector2u& size );
		// Set console fill color
		void SetFillColor( const sf::Color& fill )
		{
			this->shape.setFillColor( fill );
		}
		// Set console outline color
		void SetOutlineColor( const sf::Color& outline )
		{
			this->shape.setOutlineColor( outline );
		}
		// CONSOLE VIEW FUNCTIONS END

		// TEXT SECTION START
		// Set text color in all lines
		void SetTextColor( const sf::Color& color )
		{
			this->text.setFillColor( color );
			this->input.setFillColor( color );
		}
		// Set text font in all lines
		void SetTextFont( const sf::Font& font )
		{
			this->text.setFont( font );
			this->input.setFont( font );
		}
		// Set max number of characters in all lines
		void SetTextSizeInLine( size_t size )
		{
			this->textSizeInLine = size;
		}
		// TEXT SECTION END

		// CONSOLE FUNCTIONS START
		// Add command to commands vector
		void AddCommand( const command_t& command )
		{
			this->commands.push_back( command );
		}
		// On-Off console
		void Toggle()
		{
			this->isOpen = !this->isOpen;
		}
		// Shows console
		void Show()
		{
			this->isOpen = true;
		}
		// Hides console
		void Hide()
		{
			this->isOpen = false;
		}
		// Checks whether user click baskskape or enter
		void Key( const sf::Event& event );
		// Checks what user write on keyboard
		void Write( const sf::Event& event );
		// Write logs in console
		void Log( const std::string& message );
		// CONSOLE FUNCTIONS END

	private:
		sf::RectangleShape shape;
		sf::Vector2u windowSize;
		sf::Text text, input;
		std::array <std::string, constants::console::DEAFULT_NUMBER_OF_LINES> line;
		std::vector <command_t> commands;
		unsigned numberOfLines, textSizeInLine;
		bool isOpen;

		inline void commandInduction_r( std::string inputString );
		void draw( sf::RenderTarget& target, sf::RenderStates states ) const;
	};
}