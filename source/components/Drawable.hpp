#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include <cinttypes>
#include <vector>

namespace pg
{
	/*
	===============================================================================
	Created by: Condzi
		Drawable Component structure. It has sprites and draw layer (-128 to 127).

	===============================================================================
	*/
	struct DrawableComponent final
	{
		std::vector<sf::Sprite> sprites;
		int8_t drawLayer;

		explicit DrawableComponent( int8_t drawL = 0 ) :
			drawLayer( drawL )
		{}
	};
}