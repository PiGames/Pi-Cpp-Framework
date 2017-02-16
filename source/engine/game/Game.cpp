#include "Game.hpp"

namespace pi
{
	Game::Game(sf::Vector2u screenSize, const std::string & title, unsigned fps)
	{
		this->window.create({ screenSize.x, screenSize.y }, title, sf::Style::Close);
		this->window.setFramerateLimit(fps);

		this->console.setWindowSize(this->window.getSize());
		this->console.setFillColor({ 255,255,255, 100 });
		this->console.setTextColor({ 0,0,0,255 });

		Logger::Init("log.txt", &console);
	}

	void Game::run()
	{
		Logger::Log("\n==========\nStarting Game\n==========\n", Logger::MessageType::Separator, Logger::OutputType::Both);

		this->stateMachine.run();
		this->window.close();

		Logger::Log("\n==========\nClosing Game\n==========\n", Logger::MessageType::Separator, Logger::OutputType::Both);

	}
}
