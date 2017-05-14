#include "PlayMainSubState.hpp"

namespace pg
{
	void pg::PlayMainSubState::OnStart()
	{
		Player player( this->ecsSystem );
		player.SetUpComponents();
		auto drawable = player.AddComponent<DrawableComponent>();
		drawable->drawLayer = LAYER_PLAYER;
		drawable->sprites.emplace_back();
		drawable->sprites.back().setTexture( *this->resourceCache.GetTexture( 0 ).lock() );
		entities.push_back( std::make_shared<Player>( player ) );
	}

	void PlayMainSubState::OnStop()
	{
	}

	uint8_t PlayMainSubState::Run()
	{
		float dt = 0.0f;
		while ( this->returnState == STATE_MENU )
		{
			sf::Clock c;
			this->checkEvents();
			this->updateECS( dt );
			this->draw();
			dt = c.restart().asSeconds();
		}

		return returnState;
	}

	void PlayMainSubState::checkEvents()
	{
		sf::Event event;
		while ( this->window.pollEvent( event ) )
		{
			if ( sf::Event::Closed == event.type )
				this->returnState = STATE_EXIT;
			if ( sf::Event::KeyReleased == event.type )
				if ( sf::Keyboard::Escape == event.key.code )
					this->returnState = STATE_EXIT;
		}
	}

	void PlayMainSubState::updateECS( float dt )
	{
		// Index 0 is Player (for the tests).
		this->entities[0]->Update();
		auto velComp = this->entities[0]->GetComponent<VelocityComponent>();
		auto posComp = this->entities[0]->GetComponent<PositionComponent>();
		velComp->x += velComp->pendingForce.x;
		velComp->y += velComp->pendingForce.y;
		posComp->x += velComp->x * dt;
		posComp->y += velComp->y * dt;
		velComp->x = 0.0f;
		velComp->y = 0.0f;
		velComp->pendingForce = sf::Vector2f();
	}

	void PlayMainSubState::draw()
	{
		this->renderer.ClearWindow();
		this->renderer.Render();
		this->renderer.Display();
	}
}
