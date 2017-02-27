// Created by: Condzi
#pragma once

#include <functional>
#include <memory>
#include <map>

#include "State.hpp"
#include "engine/Config.hpp"

namespace pi
{
	/*
	 State Machine class
	 (used by Game class)
	 Starting state should be Menu
	 Usually starting state number - 0
	 State no. -1 (changable in Config.hpp) is reserved for state machine suicide, so you can use it in Menu state for example
	*/
	class StateMachine final
	{
		friend class Game;

	public:

		/*
			StateMachine constructor

			@param number of state that state machine will start (menu state for example)
		*/
		StateMachine( unsigned short stateToStart = 0 );

		/*
			Sets state id for errorus situations; if state request to change state that doesnt exist

			@param emergency state id
		*/
		void SetEmergencyStateID( short id )
		{
			this->emergencyState = id;
		}

		/*
			Adds State to StateMachine with specified id

			@param id of state; cannot be same as previulsy added (you cannot have more than one state of given 'n' number)
		*/
		template<class T, enable_if<std::is_base_of<State, T>>...>
		void AddState( short id )
		{
			auto result = states_t.find( id );

			if ( result != states_t.end() )
			{
				Logger::Log( "StateMachine: Cannot add state, found same state id! ID: " + std::to_string( id ), Logger::MessageType::Error, Logger::OutputType::Both );

				return;
			}
			states_t[id].reset( new T() );
		}

		/*
			Runs state machine
		*/
		void Run();

	private:
		short currentState;
		short emergencyState;
		std::map<short, std::unique_ptr<State>> states_t;
	};


}
