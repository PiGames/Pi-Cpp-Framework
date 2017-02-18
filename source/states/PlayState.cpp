#include "PlayState.hpp"

namespace mc
{
	void PlayState::onActivation()
	{
		// ResourceCache should return std:shared_ptrs... :/
		pi::Renderer::SetMapTexture(std::make_shared<sf::Texture>(textures.get("data/textures/textureSheet.png")));
		pi::Renderer::SetWindow(this->window);
		pi::WorldConstructor::ConstructWorld(16, 16, 123, 1, nullptr);
	}

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

			pi::Renderer::Update();

			//window->clear(sf::Color::Blue);
			//window->draw(*console);
			//player.update(*window);			
			//window->display();

			pi::Renderer::Render();
		}

		return (short)States::Exit;
	}
}

