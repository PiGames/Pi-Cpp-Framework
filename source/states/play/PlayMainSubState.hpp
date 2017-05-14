#pragma once

#include <SFML/Window/Event.hpp>

#include "states/base/SubState.hpp"
#include "states/States.hpp"
#include "resourceManaging/ResourceHolder.hpp"
#include "subsystems/Renderer.hpp"
#include "prefabs/Player.hpp"

namespace pg
{
	/*
	===============================================================================
	Created by: Condzi
		Main Play State Sub State - here is everything associated with playing.

	===============================================================================
	*/
	class PlayMainSubState final :
		public pi::SubState
	{
	public:
		explicit PlayMainSubState( sf::RenderWindow& win, pi::ResourceHolder& resCache, ecs::SystemBase& ecsSys, Renderer& rend ) :
			SubState( win ),
			resourceCache( resCache ),
			ecsSystem( ecsSys ),
			renderer( rend ),
			returnState( STATE_MENU )
		{}

		void OnStart() override;
		void OnStop() override;
		uint8_t Run() override;

	private:
		pi::ResourceHolder& resourceCache;
		ecs::SystemBase& ecsSystem;
		std::vector<std::shared_ptr<ecs::Entity>> entities;
		Renderer& renderer;
		uint8_t returnState;

		void checkEvents();
		// Temporary variable - dt, only for testing. In future it'll be Physic SubSystem
		void updateECS( float dt );
		void draw();
	};
}