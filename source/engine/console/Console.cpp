#include "Console.hpp"

namespace pi
{
	void Console::draw( sf::RenderTarget& target, sf::RenderStates state ) const
	{
		if ( this->isOpen )
		{
			target.draw( shape );
			target.draw( text );
			target.draw( input );
		}
	}

	Console::Console()
	{
		// Default settings
		this->isOpen = false;
		this->numberOfLines = constants::console::DEAFULT_NUMBER_OF_LINES;
		this->textSizeInLine = constants::console::DEAFULT_TEXT_SIZE_IN_LINE;
		// Text settings
		this->text.setFillColor( sf::Color::White );
		this->text.setCharacterSize( constants::console::DEAFULT_TEXT_SIZE );
		this->text.setPosition( { 2.f, 0 } );

		this->input.setFillColor( sf::Color::White );
		this->input.setCharacterSize( constants::console::DEAFULT_TEXT_SIZE );
		//	this->input.setPosition( { 20.f, this->window->getSize(  ).y / 2 - 20.f } );

		this->input.setString( "|" );

		// Shape
		this->shape.setPosition( { 0, 0 } );
		//	this->shape.setSize( { static_cast<float>( this->window->getSize(  ).x ), static_cast<float>( this->window->getSize(  ).y ) / 2 } );
	}

	Console::Console( const sf::Vector2u& size )
	{
		// Default settings
		this->windowSize = size;
		this->isOpen = false;
		this->numberOfLines = constants::console::DEAFULT_NUMBER_OF_LINES;;
		this->textSizeInLine = constants::console::DEAFULT_TEXT_SIZE_IN_LINE;
		// Text settings
		this->text.setFillColor( sf::Color::White );
		this->text.setCharacterSize( this->windowSize.y / 50 );
		this->text.setPosition( { 2.f, 0 } );

		this->input.setFillColor( sf::Color::White );
		this->input.setCharacterSize( this->windowSize.y / 50 );
		this->input.setPosition( { 2.f, this->windowSize.y / 2 - ( this->windowSize.y / 20.f ) } );

		this->input.setString( "|" );

		// Shape
		this->shape.setPosition( { 0, 0 } );
		this->shape.setSize( { static_cast<float>( this->windowSize.x ), static_cast<float>( this->windowSize.y ) / 2 } );
	}

	void Console::SetWindowSize( const sf::Vector2u& size )
	{
		// Default settings
		this->windowSize = size;
		this->input.setPosition( { 2.f, this->windowSize.y / 2 - ( this->windowSize.y / 20.f ) } );
		this->text.setCharacterSize( this->windowSize.y / 50 );
		this->input.setCharacterSize( this->windowSize.y / 50 );
		this->shape.setSize( { static_cast<float>( this->windowSize.x ), static_cast<float>( this->windowSize.y ) / 2 } );
	}

	void Console::SetFillColor( const sf::Color& fill )
	{
		this->shape.setFillColor( fill );

	}

	void Console::SetOutlineColor( const sf::Color& outline )
	{
		this->shape.setOutlineColor( outline );
	}

	void Console::SetTextColor( const sf::Color& color )
	{
		this->text.setFillColor( color );
		this->input.setFillColor( color );
	}

	void Console::SetTextFont( const sf::Font& font )
	{
		this->text.setFont( font );
		this->input.setFont( font );
	}

	void Console::SetTextSizeInLine( size_t size )
	{
		this->textSizeInLine = size;
	}

	void Console::AddCommand( const command_t& command )
	{
		this->commands.push_back( command );
	}

	void Console::Toggle()
	{
		this->isOpen = !this->isOpen;
	}

	void Console::Show()
	{
		this->isOpen = true;
	}

	void Console::Hide()
	{
		this->isOpen = false;
	}

	void Console::Key( const sf::Event& event )
	{
		if ( event.key.code == sf::Keyboard::Return )
		{
			if ( this->input.getString().getSize() <= textSizeInLine ) // Input text one row
			{
				// First lane
				for ( unsigned i = 0; i < this->line.size() - 1; ++i )
				{
					this->line[i] = this->line[i + 1];
				}
				this->line[line.size() - 1] = this->input.getString().substring( 0, this->input.getString().getSize() - 1 );

				// Write all string array in console text
				this->text.setString( "" );
				for ( auto &i : this->line )
				{
					this->text.setString( this->text.getString() + i + "\n" );
				}
				// Command induction
				this->commandInduction_r( this->input.getString().substring( 0, this->input.getString().getSize() - 1 ) );

				this->input.setString( "|" );
			} else if ( this->input.getString().getSize() < this->textSizeInLine * 2 ) // Input text two row
			{
				this->input.setString( this->input.getString().substring( 0, this->input.getString().getSize() - 1 ) );
				// First lane
				for ( unsigned i = 0; i < this->line.size() - 1; ++i )
				{
					this->line[i] = this->line[i + 1];
				}
				this->line[line.size() - 1] = this->input.getString().substring( 0, this->textSizeInLine - 1 );

				// Second lane
				for ( unsigned i = 0; i < this->line.size() - 1; ++i )
				{
					this->line[i] = this->line[i + 1];
				}
				this->line[line.size() - 1] = this->input.getString().substring( this->textSizeInLine, this->textSizeInLine * 2 - 1 );

				// Write all string array in console text

				this->text.setString( "" );
				for ( auto &i : this->line )
				{
					this->text.setString( this->text.getString() + i + "\n" );
				}
				// Command induction
				this->commandInduction_r( this->input.getString().substring( 0, this->input.getString().getSize() - 1 ) );

				this->input.setString( "|" );
			}
		} else if ( event.key.code == sf::Keyboard::BackSpace )
		{
			if ( this->input.getString().getSize() == 1 )
			{
				this->input.setString( "|" );
			} else
			{
				this->input.setString( this->input.getString().substring( 0, this->input.getString().getSize() - 2 ) + "|" );
			}
		}
	}

	void Console::Write( const sf::Event& event )
	{
		if ( this->input.getString().getSize() < this->textSizeInLine ) // Write in first row
		{
			this->input.setString( this->input.getString().substring( 0, this->input.getString().getSize() - 1 ) + static_cast<char>( event.text.unicode ) + "|" );
		} else if ( this->input.getString().getSize() == this->textSizeInLine ) // Jump to next row
		{
			this->input.setString( this->input.getString().substring( 0, this->input.getString().getSize() - 1 ) + "\n" + static_cast<char>( event.text.unicode ) + "|" );
		} else if ( this->input.getString().getSize() < this->textSizeInLine * 2 ) // Write in second row
		{
			this->input.setString( this->input.getString().substring( 0, this->input.getString().getSize() - 1 ) + static_cast<char>( event.text.unicode ) + "|" );
		}
	}

	void Console::Log( const std::string& message )
	{
		std::string text;
		if ( message.find( "\n" ) != std::string::npos )
		{
			text = message.substr( 0, message.find( "\n" ) );
		} else
		{
			text = message;
		}

		for ( unsigned size = 0; size < this->numberOfLines; ++size )
		{
			if ( text.size() <= this->textSizeInLine * size )
			{
				for ( unsigned write = 1; write <= size; ++write )
				{
					for ( unsigned i = 0; i < this->line.size() - 1; ++i )
					{
						this->line[i] = this->line[i + 1];
					}
					if ( write < size ) // Whatever else line option
					{
						this->line[line.size() - 1] = text.substr( 0, this->textSizeInLine );
						text = text.substr( this->textSizeInLine, std::string::npos );
					} else // Last line option
					{
						this->line[line.size() - 1] = text.substr( 0, std::string::npos );

						// Write all string array in console text
						this->text.setString( "" );
						for ( auto &i : this->line )
						{
							this->text.setString( this->text.getString() + i + "\n" );
						}
						break;
					}
				}
				// Break for first for
				break;
			}
		}

		if ( message.find( "\n" ) != std::string::npos )
		{
			this->Log( message.substr( message.find( "\n" ) + 1, std::string::npos ) );
		}
	}


	// Private

	inline void Console::commandInduction_r( std::string inputString )
	{
		if ( inputString.find( "\n" ) == std::string::npos ) // If one lane
		{
			// Create variables if one lane
			std::string argument;
			size_t spacePositionFirst, spacePositionSecond;

			// No space
			while ( inputString.find( "  " ) != std::string::npos )
			{
				inputString.erase( inputString.find( "  " ), 1 );
			}

			for ( auto &i : this->commands )
			{
				if ( i.induction == inputString.substr( 0, inputString.find( " " ) ) )
				{
					i.args.clear();
					spacePositionFirst = inputString.find( " " );
					spacePositionSecond = inputString.find( " ", spacePositionFirst + 1 );
					if ( spacePositionSecond != std::string::npos )
					{
						do
						{
							argument = inputString.substr( spacePositionFirst + 1, spacePositionSecond - spacePositionFirst - 1 );
							inputString = inputString.substr( spacePositionSecond, std::string::npos );

							// This IF is just for security
							if ( argument != " " )
								i.args.push_back( argument );

							spacePositionFirst = inputString.find( " " );
							spacePositionSecond = inputString.find( " ", spacePositionFirst + 1 );
						} while ( spacePositionSecond != std::string::npos );
					}

					if ( spacePositionFirst != std::string::npos )
					{
						argument = inputString.substr( spacePositionFirst + 1, std::string::npos );

						// This IF is just for security
						if ( argument != " " )
						{
							i.args.push_back( argument );
						}
					}

					i.function( this, &i );
				} else if ( i.induction == inputString.substr( 0, inputString.size() - 1 ) )
				{
					i.args.clear();
					i.function( this, &i );
				}
			}
		} else // If more 
		{
			inputString.erase( inputString.find( "\n" ), 2 );
			this->commandInduction_r( inputString );
		}
	}
}