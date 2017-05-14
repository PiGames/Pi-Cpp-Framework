#include "Game.hpp"

namespace pg
{
	Game::Game( const std::string& settPath, uint8_t stateToStart ) :
		stateMachine( stateToStart ),
		settingsPath( settPath )
	{
		auto& settings = Settings::GetInstance();
		if ( !settings.LoadFromFile( this->settingsPath ) )
			settings.GenerateDefault( this->settingsPath );
		else
			settings.Parse();

		this->configureFromSettings();
	}

	Game::~Game()
	{
		Settings::GetInstance().SaveToFile( this->settingsPath, "; Default config. Don't change if you don't know what are you doing!" );
		this->resourceCache.DeleteAllResources();
	}

	void Game::configureFromSettings()
	{
		pi::INIError_t error;
		auto& settings = Settings::GetInstance();

		this->window.create(
		{ (uint32_t)settings.GetInt( "WINDOW", "X", &error ),
		(uint32_t)settings.GetInt( "WINDOW", "Y", &error ) },
			settings.GetString( "WINDOW", "TITLE", &error ),
			sf::Style::Close );
		this->window.setFramerateLimit( settings.GetInt( "WINDOW", "FPS", &error ) );

		if ( !error.what.empty() )
		{
			pi::Logger::Log( "One or more errors occured loading settings (" + error.what + "), trying again..." );
			settings.GenerateDefault( this->settingsPath );
			this->configureFromSettings();
		}
	}
}