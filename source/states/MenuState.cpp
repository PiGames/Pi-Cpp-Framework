#include "MenuState.hpp"

namespace mc
{
	MenuState::MenuState()
	{

	}

	short MenuState::run()
	{
		sf::Event event;
		sf::Texture backgroundTexture, playTexture, exitTexture;
		sf::RectangleShape background;
		pi::ui::UI ui;

		backgroundTexture.loadFromFile("background.jpg");
		playTexture.loadFromFile("play.png");
		exitTexture.loadFromFile("exit.png");
		console->setTextFont(fonts.get(""));

		background.setPosition({ 0,0 });
		background.setSize({ static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y) });
		background.setTexture(&backgroundTexture);

		ui.setWindow(*window);

		pi::ui::Button *playButton = ui.add<pi::ui::Button>(),
		*exitButton = ui.add<pi::ui::Button>();

		playButton->setTexture(playTexture, playTexture);
		playButton->setPosition({ ui.getPercent(72.f, static_cast<float>(ui.getWindowSize().x)), ui.getPercent(60.f, static_cast<float>(ui.getWindowSize().y)) });
		playButton->setSize({ ui.getPercent(20.f, static_cast<float>(ui.getWindowSize().x)), ui.getPercent(15.f, static_cast<float>(ui.getWindowSize().y)) });
		playButton->addCallback([]()->void
		{

		});

		exitButton->setTexture(exitTexture, exitTexture);
		exitButton->setPosition({ ui.getPercent(72.f, static_cast<float>(ui.getWindowSize().x)), ui.getPercent(80.f, static_cast<float>(ui.getWindowSize().y)) });
		exitButton->setSize({ ui.getPercent(20.f, static_cast<float>(ui.getWindowSize().x)), ui.getPercent(15.f, static_cast<float>(ui.getWindowSize().y)) });
		exitButton->addCallback([]()->void
		{

		});

		while (window->isOpen())
		{
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					return (short)States::Exit;

				if (event.key.code == sf::Keyboard::Escape)
					console->hide();

				ui.useButtons(event);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LAlt) &&
				sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F1))
				console->show();

			window->clear(sf::Color::Black);
			window->draw(background);
			window->draw(*console);
			ui.updateButtons(*window);
			window->display();
		}

		return (short)States::Exit;
	}
}