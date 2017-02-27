#include "State.hpp"

namespace pi
{
	void State::onActivation()
	{
	}
	void State::onDeactivation()
	{
	}

	State::State()
	{
		this->window = nullptr;
	}

	void pi::State::SetWindowPointer( sf::RenderWindow * window )
	{
		if ( window == nullptr )
			Logger::Log( "states_t windows is setting using nullptr", pi::Logger::MessageType::Warning );

		this->window = window;
	}
	void State::SetConsolePointer( Console * console )
	{
		if ( console == nullptr )
			Logger::Log( "states_t console is setting using nullptr", pi::Logger::MessageType::Warning );

		this->console = console;
	}
}
