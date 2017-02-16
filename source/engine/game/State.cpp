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

	void pi::State::setWindowPointer(sf::RenderWindow * window)
	{
		if (window == nullptr)
			Logger::Log("States windows is setting using nullptr", pi::Logger::MessageType::Warning);

		this->window = window;
	}
	void State::setConsolePointer(Console * console)
	{
		if (console == nullptr)
			Logger::Log("States console is setting using nullptr", pi::Logger::MessageType::Warning);

		this->console = console;
	}
}
