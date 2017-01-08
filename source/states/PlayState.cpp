#include "PlayState.hpp"

namespace mc
{
	PlayState::PlayState()
	{
	}

	short PlayState::run()
	{
		sf::Event ev;
		console->run();

		while (window->isOpen())
		{
			while (window->pollEvent(ev))
				if (ev.type == sf::Event::Closed)
					return (short)States::Exit;

			window->clear(sf::Color::Blue);

			window->draw(*console);

			window->display();
		}

		return (short)States::Exit;
	}
}

