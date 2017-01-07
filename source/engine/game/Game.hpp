#pragma once

#include "StateMachine.hpp"
#include "engine/console/Console.hpp"

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
		Game(sf::Vector2u screenSize, const std::string& title, unsigned fps);

		template<class T, enable_if<std::is_base_of<State, T>>...>
		void AddState(unsigned short id)
		{
			m_stateMachine.addState<T>(id);
			m_stateMachine.states[id]->setWindowPointer(&m_window);
		}

		void run();

	private:
		sf::RenderWindow window;
		StateMachine stateMachine;
		Console console;
	};
}