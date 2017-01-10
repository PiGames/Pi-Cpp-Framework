#include <iostream>

#include "engine/game/Game.hpp"
#include "states/PlayState.hpp"
#include <SFML/Graphics.hpp>

int main()
{
	pi::Game game({ 1280, 720 }, "Mars Colony", 60u);

	pi::Logger::log("Mars Colony v" + std::to_string(pi::constants::version::MAJOR) + "." + std::to_string(pi::constants::version::MINOR) + "." + std::to_string(pi::constants::version::RELEASE), pi::Logger::MessageType::Info, pi::Logger::OutputType::Both);

	game.addState<mc::PlayState>((short)mc::States::Play);
	game.run();

	return 0;
}