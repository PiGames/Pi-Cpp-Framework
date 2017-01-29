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

		this->backgroundTexture.loadFromFile(pi::constants::state::menu::BG_PATH);
		this->playTexture.loadFromFile(pi::constants::state::menu::BUTTON_PLAY_PATH);
		this->exitTexture.loadFromFile(pi::constants::state::menu::BUTTON_EXIT_PATH);
		this->console->setTextFont(fonts.get(pi::constants::state::CONSOLE_FONT));

		this->background.setPosition({ 0,0 });
		this->background.setSize({ static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y) });
		this->background.setTexture(&this->backgroundTexture);

		this->playButton->setTexture(this->playTexture, this->playTexture);
		this->playButton->setPosition({ this->ui.getPercent(72.f, static_cast<float>(this->ui.getWindowSize().x)), this->ui.getPercent(60.f, static_cast<float>(this->ui.getWindowSize().y)) });
		this->playButton->setSize({ this->ui.getPercent(20.f, static_cast<float>(this->ui.getWindowSize().x)), this->ui.getPercent(15.f, static_cast<float>(this->ui.getWindowSize().y)) });
		this->playButton->addCallback([=]()->void
		{
			this->isPlay = true;
		});

		this->exitButton->setTexture(this->exitTexture, this->exitTexture);
		this->exitButton->setPosition({ this->ui.getPercent(72.f, static_cast<float>(this->ui.getWindowSize().x)), this->ui.getPercent(80.f, static_cast<float>(this->ui.getWindowSize().y)) });
		this->exitButton->setSize({ this->ui.getPercent(20.f, static_cast<float>(this->ui.getWindowSize().x)), this->ui.getPercent(15.f, static_cast<float>(this->ui.getWindowSize().y)) });
		this->exitButton->addCallback([=]()->void
		{
			this->isExit = true;
		});

		this->music.openFromFile((std::string)pi::constants::state::menu::MUSIC_MAIN_PATH);
		this->music.setLoop(true);

		this->isInitialized = true;
	}

	short MenuState::run()
	{
		sf::Event event;

		if (!isInitialized)
			this->initialize();

		this->isPlay = false;
		this->isExit = false;

		this->music.play();

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

			if (this->isPlay)
			{
				this->music.stop();
				return (short)States::Play;
			}
			if (this->isExit)
			{
				this->music.stop();
				return (short)States::Exit;
			}

			this->window->clear(sf::Color::Black);
			this->window->draw(this->background);
			this->window->draw(*this->console);
			this->ui.updateButtons(*this->window);
			this->window->display();
		}

		return (short)States::Exit;
	}
}