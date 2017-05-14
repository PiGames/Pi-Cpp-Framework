#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <functional>

// Forward declarations
namespace ecs
{
	class SystemBase;
}
namespace pg
{
	enum collidedDirection_t;
	struct physicEntity_t;
}
namespace pg
{
	/*
	===============================================================================
	Created by: Condzi
		Collider Component structure extended by sf::FloatRect.

	===============================================================================
	*/
	struct ColliderComponent final :
		public sf::FloatRect
	{
		std::function<void( physicEntity_t&, physicEntity_t&, collidedDirection_t, ecs::SystemBase& )> callback;

		ColliderComponent( const sf::FloatRect rect = sf::FloatRect() ) :
			sf::FloatRect( rect )
		{}
	};
}