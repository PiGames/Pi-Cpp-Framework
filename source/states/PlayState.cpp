#include "PlayState.hpp"

namespace mc
{
	void PlayState::onActivation()
	{
		// ResourceCache should return std:shared_ptrs... :/
		pi::Renderer::SetMapTexture( std::make_shared<sf::Texture>( textures.Get( "data/textures/textureSheet.png" ) ) );
		pi::Renderer::SetWindow( this->window );
		pi::WorldConstructor::ConstructWorld( 16, 16, 123, 1, nullptr );
	}

	PlayState::PlayState()
	{
	}

	short PlayState::Run()
	{
		// Player
		sf::Texture texture;
		texture.loadFromFile( "player.png" );
		mc::Player player( texture );

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
				player.Move( mc::Player::direction_t::UP );
			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::D ) || sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
				player.Move( mc::Player::direction_t::RIGHT );
			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::A ) || sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
				player.Move( mc::Player::direction_t::LEFT );
			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::S ) || sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
				player.Move( mc::Player::direction_t::DOWN );

			pi::Renderer::Update();

			//window->clear(sf::Color::Blue);
			//window->draw(*console);
			//player.update(*window);			
			//window->display();

			pi::Renderer::Render();
		}

		return (short)states_t::Exit;
	}
}

