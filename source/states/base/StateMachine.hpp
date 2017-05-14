#pragma once

#include <functional>
#include <cassert>
#include <unordered_map>
#include <memory>
#include "State.hpp"

namespace pi
{
	/*
	===============================================================================
	Created by: Condzi
		State Machine class. It cannot be copied or assigned. You must register
		states before using!

	===============================================================================
	*/
	class StateMachine
	{
	public:
		explicit StateMachine( uint8_t startState = 0 ) :
			actualState( startState )
		{}

		StateMachine( const StateMachine& ) = delete;
		const StateMachine& operator=( const StateMachine& ) = delete;

		void SetCurrentStateID( uint8_t id ) 
		{ 
			this->actualState = id; 
		}

		template<class T, typename... Args>
		typename std::enable_if<std::is_base_of<State, T>::value>::type
		RegisterState( uint8_t id, Args&&... args )
		{
			this->factories[id] = [&args..., this]()
			{
				return std::make_unique<T>( std::forward<Args>( args )... );
			};
		}

		void Run();

	private:
		std::unordered_map<uint8_t, std::unique_ptr<State>> stack;
		std::unordered_map<uint8_t, std::function<std::unique_ptr<State>()>> factories;
		uint8_t actualState;

		std::unique_ptr<State> createState( uint8_t id );
	};
}
