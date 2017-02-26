#include <iostream>

#include <SFML/Graphics.hpp>

#include "engine/game/Game.hpp"
#include "states/PlayState.hpp"
#include "states/MenuState.hpp"

int main()
{
	try
	{
		pi::Game game( { 1280, 720 }, "Mars Colony", 60u );

		pi::Logger::Log( "Mars Colony v" + std::to_string( pi::constants::version::MAJOR ) + "." + std::to_string( pi::constants::version::MINOR ) + "." + std::to_string( pi::constants::version::RELEASE ), pi::Logger::MessageType::Info, pi::Logger::OutputType::Both );

		game.AddState<mc::MenuState>( (short)mc::States::Menu );
		game.AddState<mc::PlayState>( (short)mc::States::Play );
		game.Run();
	} catch ( std::exception& e )
	{
		pi::Logger::Log( "EXCPTION: " + *e.what(), pi::Logger::MessageType::Error, pi::Logger::OutputType::Both );
		std::cin.get();
	}


	return 0;
}