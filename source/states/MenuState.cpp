#include "MenuState.hpp"

namespace mc
{
	MenuState::MenuState()
	{
		this->playButton = this->ui.add<pi::ui::Button>();
		this->exitButton = this->ui.add<pi::ui::Button>();
		this->isInitialized = false;
	}

	void MenuState::initialize()
	{
		this->ui.setWindow(*window);

		this->backgroundTexture.loadFromFile("background.jpg");
		this->playTexture.loadFromFile("play.png");
		this->exitTexture.loadFromFile("exit.png");
		this->console->setTextFont(fonts.get(""));

		this->background.setPosition({ 0,0 });
		this->background.setSize({ static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y) });
		this->background.setTexture(&this->backgroundTexture);

		this->playButton->setTexture(this->playTexture, this->playTexture);
		this->playButton->setPosition({ this->ui.getPercent(72.f, static_cast<float>(this->ui.getWindowSize().x)), this->ui.getPercent(60.f, static_cast<float>(this->ui.getWindowSize().y)) });
		this->playButton->setSize({ this->ui.getPercent(20.f, static_cast<float>(this->ui.getWindowSize().x)), this->ui.getPercent(15.f, static_cast<float>(this->ui.getWindowSize().y)) });
		this->playButton->addCallback([]()->void
		{

		});

		this->exitButton->setTexture(this->exitTexture, this->exitTexture);
		this->exitButton->setPosition({ this->ui.getPercent(72.f, static_cast<float>(this->ui.getWindowSize().x)), this->ui.getPercent(80.f, static_cast<float>(this->ui.getWindowSize().y)) });
		this->exitButton->setSize({ this->ui.getPercent(20.f, static_cast<float>(this->ui.getWindowSize().x)), this->ui.getPercent(15.f, static_cast<float>(this->ui.getWindowSize().y)) });
		this->exitButton->addCallback([]()->void
		{

		});

		this->isInitialized = true;
	}

	short MenuState::run()
	{
		sf::Event event;

		if (!isInitialized)
			this->initialize();

		while (this->window->isOpen())
		{
			while (this->window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					return (short)States::Exit;

				if (event.key.code == sf::Keyboard::Escape)
					this->console->hide();

				this->ui.useButtons(event);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LAlt) &&
				sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F1))
				this->console->show();

			this->window->clear(sf::Color::Black);
			this->window->draw(this->background);
			this->window->draw(*this->console);
			this->ui.updateButtons(*this->window);
			this->window->display();
		}

		return (short)States::Exit;
	}
}