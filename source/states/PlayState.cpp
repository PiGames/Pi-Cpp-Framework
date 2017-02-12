#include "PlayState.hpp"

namespace mc
{
	PlayState::PlayState()
	{
	}

	short PlayState::run()
	{
		// Player
		sf::Texture texture;
		texture.loadFromFile("player.png");
		mc::Player player(texture);

		sf::Event ev;

		console->setTextFont(fonts.get(pi::constants::state::CONSOLE_FONT));

		while (window->isOpen())
		{
			while (window->pollEvent(ev))
			{
				if (ev.type == sf::Event::Closed)
					return (short)States::Exit;

				if (ev.key.code == sf::Keyboard::Escape)
					console->hide();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LAlt) &&
				sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F1))
				console->show();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
				player.move(mc::Player::Direction::UP);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
				player.move(mc::Player::Direction::RIGHT);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
				player.move(mc::Player::Direction::LEFT);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
				player.move(mc::Player::Direction::DOWN);

			window->clear(sf::Color::Blue);

			window->draw(*console);

			window->display();
		}

		return (short)States::Exit;
	}
}

