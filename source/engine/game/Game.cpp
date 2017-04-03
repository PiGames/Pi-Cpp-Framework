#include "Game.hpp"

namespace pi
{
	Game::Game( sf::Vector2u screenSize, const std::string & title, int fps )
	{
		this->window.create( { screenSize.x, screenSize.y }, title, sf::Style::Close );
		this->window.setFramerateLimit( fps );

		this->console.SetWindowSize( this->window.getSize() );
		this->console.SetFillColor( { 255, 255, 255, 100 } );
		this->console.SetTextColor( { 0, 0, 0, 255 } );

		Logger::Init( "log.txt", &console );
	}

	void Game::Run()
	{
		Logger::Log( "\n==========\nStarting Game\n==========\n", Logger::MessageType::Separator, Logger::OutputType::Both );

		this->stateMachine.Run();
		this->window.close();

		Logger::Log( "\n==========\nClosing Game\n==========\n", Logger::MessageType::Separator, Logger::OutputType::Both );

	}
}
