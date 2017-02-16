#include "StateMachine.hpp"

namespace pi
{
	StateMachine::StateMachine(unsigned short stateToStart)
	{
		this->currentState = stateToStart;
		this->emergencyState = 0;
	}

	void StateMachine::setEmergencyStateID(short id)
	{
		this->emergencyState = id;
	}

	void StateMachine::run()
	{
		if (!states.size())
		{
			Logger::Log(constants::error::stateMachine::NO_STATES, Logger::MessageType::Error);

			return;
		}

		short nextState = this->currentState;

		while (nextState != constants::stateMachine::EXIT_STATE)
		{
			this->states[this->currentState]->onActivation();
			nextState = this->states[this->currentState]->run();

			if (nextState != this->currentState)
			{
				this->states[this->currentState]->onDeactivation();

				auto result = this->states.find(nextState);

				if (result == this->states.end())
				{
					Logger::Log(constants::error::stateMachine::CANNOT_SWITCH + std::to_string(this->emergencyState), Logger::MessageType::Warning, Logger::OutputType::Console);

					this->currentState = emergencyState;
				}
				else
					this->currentState = nextState;
			}
		}
	}
}
