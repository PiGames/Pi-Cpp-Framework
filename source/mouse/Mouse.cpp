#include "Mouse.hpp"

namespace mc
{
	Mouse::Mouse( const std::string & name, const sf::Vector2f & pos )
		:MapObject( name, pos )
	{
		pi::TextureCache textureAtlas;
		object.setTexture( textureAtlas.Get( pi::constants::mouse::TEXTURE_PATH ) );
		SetCursor( Mouse::TYPE::SIMPLE );
	}

	void Mouse::SetCursor( Mouse::TYPE type )
	{
		object.setTextureRect( sf::IntRect( type * pi::constants::mouse::dimensions.x, 0, pi::constants::mouse::dimensions.x, pi::constants::mouse::dimensions.y ) );
	}
}
