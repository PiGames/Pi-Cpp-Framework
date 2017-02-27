#pragma once

#include "engine/console/Console.hpp"

#include "StateMachine.hpp"

namespace pi
{
	class Game final
	{
	public:
		template<typename CONDITION>
		using enable_if = typename std::enable_if<CONDITION::value>::type;

		/*
			Game class constructor

			@param screen size
			@param window title
			@param framerate limit
		*/
		Game( sf::Vector2u screenSize, const std::string& title, int fps );

		template<class T, enable_if<std::is_base_of<State, T>>...>
		void AddState( unsigned short id )
		{
			this->stateMachine.AddState<T>( id );
			this->stateMachine.states_t[id]->SetWindowPointer( &window );
			this->stateMachine.states_t[id]->SetConsolePointer( &console );
		}

		void Run();

	private:
		sf::RenderWindow window;
		StateMachine stateMachine;
		Console console;
	};
}