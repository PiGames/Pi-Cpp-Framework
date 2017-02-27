#include "MenuState.hpp"

namespace mc
{
	MenuState::MenuState()
	{
		this->playButton = this->ui.Add<pi::ui::Button>();
		this->exitButton = this->ui.Add<pi::ui::Button>();
		this->isInitialized = false;
	}

	void MenuState::initialize()
	{
		this->ui.SetWindow( *window );

		this->backgroundTexture.loadFromFile( "data/textures/background.jpg" );
		this->playTexture.loadFromFile( "data/textures/play.png" );
		this->exitTexture.loadFromFile( "data/textures/exit.png" );
		this->console->SetTextFont( fonts.Get( "data/music/menu.ogg" ) );

		this->background.setPosition( { 0, 0 } );
		this->background.setSize( { static_cast<float>( this->window->getSize().x ), static_cast<float>( this->window->getSize().y ) } );
		this->background.setTexture( &this->backgroundTexture );

		this->playButton->SetTexture( this->playTexture, this->playTexture );
		this->playButton->SetPosition( { this->ui.GetPercent( 72.f, static_cast<float>( this->ui.GetWindowSize().x ) ), this->ui.GetPercent( 60.f, static_cast<float>( this->ui.GetWindowSize().y ) ) } );
		this->playButton->SetSize( { this->ui.GetPercent( 20.f, static_cast<float>( this->ui.GetWindowSize().x ) ), this->ui.GetPercent( 15.f, static_cast<float>( this->ui.GetWindowSize().y ) ) } );
		this->playButton->AddCallback( [=] ()->void
		{
			this->isPlay = true;
		} );

		this->exitButton->SetTexture( this->exitTexture, this->exitTexture );
		this->exitButton->SetPosition( { this->ui.GetPercent( 72.f, static_cast<float>( this->ui.GetWindowSize().x ) ), this->ui.GetPercent( 80.f, static_cast<float>( this->ui.GetWindowSize().y ) ) } );
		this->exitButton->SetSize( { this->ui.GetPercent( 20.f, static_cast<float>( this->ui.GetWindowSize().x ) ), this->ui.GetPercent( 15.f, static_cast<float>( this->ui.GetWindowSize().y ) ) } );
		this->exitButton->AddCallback( [=] ()->void
		{
			this->isExit = true;
		} );

		this->music.openFromFile( "data/music/menu.ogg" );
		this->music.setLoop( true );

		this->isInitialized = true;
	}

	short MenuState::Run()
	{
		sf::Event event;

		if ( !isInitialized )
			this->initialize();

		this->isPlay = false;
		this->isExit = false;

		this->music.play();

		while ( this->window->isOpen() )
		{
			while ( this->window->pollEvent( event ) )
			{
				if ( event.type == sf::Event::Closed )
					return (short)states_t::Exit;

				if ( event.key.code == sf::Keyboard::Escape )
					this->console->Hide();

				this->ui.UseButtons( event );
			}

			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::LAlt ) &&
				sf::Keyboard::isKeyPressed( sf::Keyboard::Key::F1 ) )
				this->console->Show();

			if ( this->isPlay )
			{
				this->music.stop();
				return (short)states_t::Play;
			}
			if ( this->isExit )
			{
				this->music.stop();
				return (short)states_t::Exit;
			}

			this->window->clear( sf::Color::Black );
			this->window->draw( this->background );
			this->window->draw( *this->console );
			this->ui.UpdateButtons( *this->window );
			this->window->display();
		}

		return (short)states_t::Exit;
	}
}