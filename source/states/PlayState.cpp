#include "PlayState.hpp"

namespace mc
{
	void PlayState::onActivation()
	{
		// ResourceCache should return std:shared_ptrs... :/
		pi::Renderer::SetMapTexture( std::make_shared<sf::Texture>( textures.Get( "data/textures/textureSheet.png" ) ) );
		pi::Renderer::SetWindow( this->window );
		pi::WorldConstructor::ConstructWorld( 16, 16, 123, 1, nullptr );

		view = window->getDefaultView();
		sf::Vector2u textureSize = player.GetTexture()->getSize();
		view.setCenter(player.GetPosition().x + textureSize.x / 2, player.GetPosition().y + textureSize.y / 2);
	}

	PlayState::PlayState() : player( textures.Get( "data/textures/play.png" ) )
	{
		
	}

	short PlayState::Run()
	{
		sf::Event ev;

		console->SetTextFont( fonts.Get( pi::constants::state::CONSOLE_FONT ) );

		while ( window->isOpen() )
		{
			while ( window->pollEvent( ev ) )
			{
				if ( ev.type == sf::Event::Closed )
					return (short)states_t::Exit;

				if ( ev.key.code == sf::Keyboard::Escape )
					console->Hide();
			}

			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::LAlt ) &&
				sf::Keyboard::isKeyPressed( sf::Keyboard::Key::F1 ) )
				console->Show();

			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::W ) || sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
				player.Move( mc::Player::direction_t::UP, &view );
			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::D ) || sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
				player.Move( mc::Player::direction_t::RIGHT, &view );
			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::A ) || sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
				player.Move( mc::Player::direction_t::LEFT, &view );
			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::S ) || sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
				player.Move( mc::Player::direction_t::DOWN, &view );

			window->setView( view );

			window->clear();

			pi::Renderer::Update();

			//window->clear(sf::Color::Blue);
			//window->draw(*console);
			player.Update( *window );
			//window->display();

			pi::Renderer::Render();

			window->display();
		}

		return (short)states_t::Exit;
	}
}

