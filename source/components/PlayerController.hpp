#pragma once

#include <SFML/Window/Event.hpp>

namespace pg
{
	/*
	===============================================================================
	Created by: Condzi
		Movement Key Type structure is used by Player Controller Component. It has
		`key` field, which is a key that have to be pressed to apply `force` values
		to the Velocity Component in Player.

	===============================================================================
	*/
	struct movementKey_t
	{
		sf::Keyboard::Key key;
		sf::Vector2f force;

		movementKey_t( sf::Keyboard::Key k = sf::Keyboard::Key::Unknown, const sf::Vector2f& f = sf::Vector2f() ) :
			key( k ),
			force( f )
		{}
	};

	/*
	===============================================================================
	Created by: Condzi
		Player Controller Component class used by Player class to help in moving.

	===============================================================================
	*/
	struct PlayerControllerComponent final
	{
		movementKey_t left, right, jump;
		// Automaticly sets to true when jump key is pressed and lockJump is false.
		bool lockJump;
		sf::Vector2f pendingForce;

		PlayerControllerComponent() :
			lockJump( false ),
			pendingForce( 0.0f, 0.0f )
		{}
	};
}