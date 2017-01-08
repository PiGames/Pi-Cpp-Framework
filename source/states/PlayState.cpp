#include "PlayState.hpp"

namespace mc
{
	PlayState::PlayState()
	{
	}

	short PlayState::run()
	{
		sf::Event ev;

		console->setTextFont(fonts.get(""));

		while (window->isOpen())
		{
			while (window->pollEvent(ev))
			{
				if (ev.type == sf::Event::Closed)
					return (short)States::Exit;

				if (ev.key.code == sf::Keyboard::Key::F1)
					console->show();

				if (ev.key.code == sf::Keyboard::Key::F2)
					console->hide();
			}

			window->clear(sf::Color::Blue);

			window->draw(*console);

			window->display();
		}

		return (short)States::Exit;
	}
}

