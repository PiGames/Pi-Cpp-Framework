#include "StateMachine.hpp"

namespace pi
{
	StateMachine::StateMachine( unsigned short stateToStart )
	{
		this->currentState = stateToStart;
		this->emergencyState = 0;
	}

	void StateMachine::Run()
	{
		if ( !states_t.size() )
		{
			Logger::Log( constants::error::stateMachine::NO_STATES, Logger::MessageType::Error );

			return;
		}

		short nextState = this->currentState;

		while ( nextState != constants::stateMachine::EXIT_STATE )
		{
			this->states_t[this->currentState]->onActivation();
			nextState = this->states_t[this->currentState]->Run();

			if ( nextState != this->currentState )
			{
				this->states_t[this->currentState]->onDeactivation();

				auto result = this->states_t.find( nextState );

				if ( result == this->states_t.end() )
				{
					Logger::Log( constants::error::stateMachine::CANNOT_SWITCH + std::to_string( this->emergencyState ), Logger::MessageType::Warning, Logger::OutputType::Console );

					this->currentState = emergencyState;
				} else
					this->currentState = nextState;
			}
		}
	}
}
