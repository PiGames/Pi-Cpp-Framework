#include <iostream>

#include <SFML/Graphics.hpp>

#include "engine/game/Game.hpp"
#include "States/PlayState.hpp"
#include "States/MenuState.hpp"

int main()
{
	try
	{
		pi::ResourceHolder::Initialize();
		pi::Game game( { 1280, 720 }, "Mars Colony", 60u );

		pi::Logger::Log( "Mars Colony v" + std::to_string( pi::constants::version::MAJOR ) + "." + std::to_string( pi::constants::version::MINOR ) + "." + std::to_string( pi::constants::version::RELEASE ), pi::Logger::MessageType::Info, pi::Logger::OutputType::Both );

		game.AddState<mc::MenuState>( (short)mc::states_t::Menu );
		game.AddState<mc::PlayState>( (short)mc::states_t::Play );
		game.Run();

		pi::ResourceHolder::Shutdown();

	} catch ( std::exception& e )
	{
		pi::Logger::Log( "EXCPTION: " + *e.what(), pi::Logger::MessageType::Error, pi::Logger::OutputType::Both );
		std::cin.get();
	}

	return 0;
}
