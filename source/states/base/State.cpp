#include "State.hpp"

namespace pi
{
	void State::StartThread()
	{
		this->lockWindowContext();
		this->threadRunning = true;

		this->thread = std::thread( &State::ThreadMethod, this );
	}

	void State::EndThread()
	{
		this->threadRunning = false;
		this->thread.join();

		this->unlockWindowContext();
	}

	void State::ThreadMethod()
	{
		this->unlockWindowContext();

		while ( this->threadRunning )
			this->UpdateThread( 1 / 30.0f );

		this->lockWindowContext();
	}

	void State::initFirstSubState( uint8_t id )
	{
	#if defined _DEBUG // We don't need this check - Release won't have this type of bugs. Seriously. 
		if ( !this->hasSubState( id ) )
		{
			Logger::Log( "Cannot init first SubState, cannot found ID: " + std::to_string( id ), Logger::BOTH, Logger::ERROR );
			return;
		}
	#endif

		this->currentSubState = id;
		this->subStates[this->currentSubState]->OnStart();
	}

	void State::switchSubState( uint8_t id )
	{
	#if defined _DEBUG // We don't need this check - Release won't have this type of bugs. Seriously. 
		if ( !this->hasSubState( id ) )
		{
			Logger::Log( "Cannot switch SubState, cannot found ID: " + std::to_string( id ), Logger::BOTH, Logger::ERROR );
			return;
		}
	#endif

		this->subStates[id]->OnStop();
		this->currentSubState = id;
		this->subStates[id]->OnStart();
	}
}