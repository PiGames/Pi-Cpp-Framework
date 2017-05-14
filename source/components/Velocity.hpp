/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#pragma once

#include <SFML/System/Vector2.hpp>

namespace pg
{
	/*
	===============================================================================
	Created by: Condzi
		Velocity Component structure extended by sf::Vector2f.

	===============================================================================
	*/
	struct VelocityComponent final :
		public sf::Vector2f
	{
		// Pending Force is added in physic update to velocity.
		sf::Vector2f pendingForce;

		VelocityComponent( const sf::Vector2f& vec = sf::Vector2f() ) :
			sf::Vector2f( vec ),
			pendingForce( 0.0f, 0.0f )
		{}
	};
}
