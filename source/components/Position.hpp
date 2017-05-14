#pragma once

#include <SFML/System/Vector2.hpp>

namespace pg
{
	/*
	===============================================================================
	Created by: Condzi
		Position Component structure extended by sf::Vector2f.

	===============================================================================
	*/
	struct PositionComponent final :
		public sf::Vector2f
	{
		PositionComponent( const sf::Vector2f& vec = sf::Vector2f() ) :
			sf::Vector2f( vec )
		{}
	};
}