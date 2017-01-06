#pragma once
#include "State.hpp"


// State Machine
// (used by Game class)
// Starting state should be Menu 
// Usually starting state number - 0

class StateMachine
{
	friend class Game;
public:
	// StateMachine constructor (default)
	// stateToStart = 0	- number of state to start
	StateMachine(unsigned short stateToStart = 0);
	~StateMachine();
	// Add State to StateMachine with specified id
	// Usage: stateMachine.AddState< MenuState >((int)StateEnums::MenuState, "resrc/menu.config")
	// id						- id of state (cannot be the same as added previous)
	// resourceCachePath		- path to resource cache
	template<class T>
	inline void AddState(unsigned short id, const std::string & resourceCachePath)
	{
		static_assert(std::is_base_of<State, T>::value, "State is not base of T");

		for (auto it = m_states.begin(); it != m_states.end(); ++it)
		{
			if (it->first == id)
			{
				Logger::Log("StateMachine: Cannot add state, found same state id! ID: " + std::to_string(id), Logger::MessageType::Error, Logger::Output::All);

				return;
			}
		}

		m_states[id] = new T(resourceCachePath);
	}
	// Runs state machine
	void run();

private:
	unsigned short currentState;
	std::map<unsigned short, State*> m_states;
};

