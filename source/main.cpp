#include <iostream>

#include <SFML/Graphics.hpp>

#include "engine/game/Game.hpp"
#include "States/PlayState.hpp"
#include "States/MenuState.hpp"

#include <engine/resourceCache/ResourceCache.hpp>

//int main()
//{
//	try
//	{
//		pi::Game game( { 1280, 720 }, "Mars Colony", 60u );
//
//		pi::Logger::Log( "Mars Colony v" + std::to_string( pi::constants::version::MAJOR ) + "." + std::to_string( pi::constants::version::MINOR ) + "." + std::to_string( pi::constants::version::RELEASE ), pi::Logger::MessageType::Info, pi::Logger::OutputType::Both );
//
//		game.AddState<mc::MenuState>( (short)mc::states_t::Menu );
//		game.AddState<mc::PlayState>( (short)mc::states_t::Play );
//		game.Run();
//	} catch ( std::exception& e )
//	{
//		pi::Logger::Log( "EXCPTION: " + *e.what(), pi::Logger::MessageType::Error, pi::Logger::OutputType::Both );
//		std::cin.get();
//	}
//
//	return 0;
//}

#include "engine/resourceCache/ResourceCache.hpp"

enum testEnum
{
	A = 0,
	B
};

struct testRes
{
	bool loadFromFile( const std::string& path )
	{
		pi::Logger::Log( "Loaded!" );

		return true;
	}

	testRes() :
		Val( 0 )
	{}

	int Val;
};

int main()
{
	pi::ResourceCache<testRes, testEnum> res;

	res.SetLoadingMethod( &testRes::loadFromFile );
	res.AddResourcePath( testEnum::A, "somePath" );

	res.Get( testEnum::A )->Val = 123;
	std::cout<<res.Get( testEnum::A )->Val << "\n";
	res.Get( testEnum::B );
	res.Release(testEnum::A, true );
	std::cout << res.Get( testEnum::A )->Val;

	std::cin.get();
}