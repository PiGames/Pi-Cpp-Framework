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
			Logger::log("States windows is setting using nullptr", pi::Logger::MessageType::Warning);

		this->window = window;
	}
}
