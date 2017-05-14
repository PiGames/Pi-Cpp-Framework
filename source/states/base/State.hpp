#pragma once

#include <atomic>
#include <thread>
#include <unordered_map>

#include <SFML/Graphics/RenderWindow.hpp>

#include "SubState.hpp"
#include "logger/Logger.hpp"

namespace pi
{
	/*
	===============================================================================
	Created by: Condzi
		Virtual State class. You can make load screen with it. You must overwrite
		OnStart, OnStop, Run and UpdateThread. It's extended SubState class.

	===============================================================================
	*/
	class State :
		public SubState
	{
	public:
		explicit State( sf::RenderWindow& win ) :
			SubState( win ),
			threadRunning( false ),
			currentSubState( 0 ),
			currentSubStateRO( this->currentSubState )
		{}
		virtual ~State() = default;

		State( const State& ) = delete;
		const State& operator =( const State& ) = delete;

		// Call it when you need to load resources and you don't want to freeze window
		// Don't forget to call EndThread() 
		void StartThread();
		void EndThread();
		// updates thread (like update method in entities)
		virtual void UpdateThread( float time ) = 0;
		// This method is called when thread is stared - it's its loop
		virtual void ThreadMethod();

	protected:
		std::unordered_map<uint8_t, std::unique_ptr<SubState>> subStates;
		// RO at the end means this variable is read-only.
		const uint8_t& currentSubStateRO;

		inline void unlockWindowContext()
		{
			this->window.setActive( true );
		}
		inline void lockWindowContext()
		{
			this->window.setActive( false );
		}

		inline bool hasSubState( uint8_t id )
		{
			return this->subStates.find( id ) != this->subStates.end();
		}

		void initFirstSubState( uint8_t id );
		void switchSubState( uint8_t id );

		template<class T, class ...Args>
		typename std::enable_if<std::is_base_of<SubState, T>::value>::type
		addSubState( uint8_t id, Args&& ...args );

	private:
		std::thread thread;
		std::atomic_bool threadRunning;
		uint8_t currentSubState;
	};

#include "State.inl"
}