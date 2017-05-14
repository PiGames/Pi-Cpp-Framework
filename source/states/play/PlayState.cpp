#include "PlayState.hpp"

namespace pg
{
	void PlayState::OnStart()
	{
		this->StartThread();

		this->mapManager.createWorld( 0 );

		this->loadTextures();
		this->renderer.SetComponentBlocks( *this->ecsSystem.ReserveComponentBlocks<DrawableComponent>( 8 ) );
		this->renderer.SetMapTextureSheet( this->resourceCache.GetTexture( 1 ) );
		this->renderer.GenerateMapTexture( mapManager );

		this->addSubState<PlayMainSubState>( SUB_STATE_PLAY_MAIN, this->window, this->resourceCache, this->ecsSystem, this->renderer );
		this->EndThread();
	}

	void PlayState::OnStop()
	{
		this->StartThread();
		this->ecsSystem.ClearAll();
		this->freeResources();
		this->EndThread();
	}

	uint8_t PlayState::Run()
	{
		this->initFirstSubState( SUB_STATE_PLAY_MAIN );

		uint8_t returnState = STATE_PLAY;
		while ( returnState == STATE_PLAY )
			returnState = this->subStates[this->currentSubStateRO]->Run();

		return STATE_EXIT;
	}

	void PlayState::UpdateThread( float time )
	{
		// Draw loading screen or smh
	}

	void PlayState::loadTextures()
	{
		this->resourceCache.textures.emplace_back( std::make_shared<pi::textureResource_t>() );
		this->resourceCache.textures.back()->loadFromFile( "data/textures/playerPlaceholder.png" );
		this->resourceCache.textures.back()->SetResourcePriority( 0 );
		this->resourceCache.textures.back()->SetResourceID( 0 );

		this->resourceCache.textures.emplace_back( std::make_shared<pi::textureResource_t>() );
		this->resourceCache.textures.back()->loadFromFile( "data/textures/cellAtlas.png" );
		this->resourceCache.textures.back()->SetResourcePriority( 0 );
		this->resourceCache.textures.back()->SetResourceID( 1 );
	}

	void PlayState::freeResources()
	{
		this->resourceCache.DeleteAllResourcesByPriority( 0 );
	}
}