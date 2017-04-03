#include "Mouse.hpp"

namespace mc
{
	Mouse::Mouse( std::weak_ptr<sf::Texture> texture, const std::string & name, const sf::Vector2f & pos )
		:MapObject( texture, name, pos )
	{
		SetCursor( Mouse::type_t::SIMPLE );
	}

	void Mouse::ProcessEvent( const sf::Event& event, const sf::RenderWindow& window )
	{
		if ( event.type == sf::Event::MouseMoved )
		{
			this->SetPosition( sf::Mouse::getPosition( window ) );
		}
	}

	void Mouse::SetCursor( Mouse::type_t type )
	{
		object.setTextureRect( sf::IntRect( static_cast<int>( type ) * pi::constants::mouse::dimensions.x, 0, pi::constants::mouse::dimensions.x, pi::constants::mouse::dimensions.y ) );
	}
}
