#include <iostream>

#include "engine/game/Game.hpp"

int main()
{
	pi::Game game({ 800,600 }, "Mars Colony", 60u);

	pi::Logger::log("Mars Colony v" + std::to_string(pi::constants::version::MAJOR) + "." + std::to_string(pi::constants::version::MINOR) + "." + std::to_string(pi::constants::version::RELEASE), pi::Logger::MessageType::Info, pi::Logger::OutputType::Both);

	game.run();

	return 0;
}