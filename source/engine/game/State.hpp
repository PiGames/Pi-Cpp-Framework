// Created by: Condzi
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "engine/Logger.hpp"

namespace pi
{
	/*
		State class
		Mehtods to override:
		void onActivation()
		void onDeactivation()
		short run()
	*/
	class State
	{
		friend class StateMachine;

	private:
		/*
			State Machine calls this method before run method, you don't need to override it
		*/
		virtual void onActivation();
		/*
			State Machine calls this method before switching to other one (after run method), you don't need to override it
		*/
		virtual void onDeactivation();

	public:
		State();
		virtual ~State() = default;

		/*
			Sets window pointer

			@param pointer to window
		*/
		void setWindowPointer(sf::RenderWindow* window);

		/*
			Sets console pointer

			@param pointer to Console
		*/
		void setConsolePointer(Console* console);
		/*
			Runs state loop

			@return id of state that is requested to change to (-1 (changable in Config.hpp) is reserved for exit)
		*/
		virtual short run() = 0;

	protected:
		sf::RenderWindow * window;
		Console * console;
	};
}
