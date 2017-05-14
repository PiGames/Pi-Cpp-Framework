#pragma once

#include "States.hpp"
#include "states/base/StateMachine.hpp"
#include "Settings.hpp"
#include "resourceManaging/ResourceHolder.hpp"
#include "ecs/ECS.hpp"

namespace pg
{
	/*
	===============================================================================
	Created by: Condzi
		Game class is a wrapper for State Machine. It does Settings loading and
		creates window.

	===============================================================================
	*/
	class Game final
	{
	public:
		Game( const std::string& settPath, uint8_t stateToStart = STATE_MENU );
		~Game();

		// We are assuming that State arguments are (in order):
		// sf::RenderWindow&, ResourceCache&, ecs::SystemBase& 
		template<class T>
		void RegisterState( uint8_t id )
		{
			this->stateMachine.RegisterState<T>( id, this->window, this->resourceCache, this->ecsSystem );
		}
		// Runs State Machine
		void Run()
		{
			this->stateMachine.Run();
		}

	private:
		sf::RenderWindow window;
		pi::ResourceHolder resourceCache;
		// Temporary placholder - change to UI and Basic in future
		ecs::SystemBase ecsSystem;
		const std::string settingsPath;
		pi::StateMachine stateMachine;

		void configureFromSettings();
	};
}
