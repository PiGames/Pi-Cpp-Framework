#pragma once

#include <vector>
#include <string>

#include "engine/Logger.hpp"

#include "ColliderComponent.hpp"

namespace mc
{
	class CollisionHandler final
	{
	public:
		CollisionHandler() {}

		void RegisterCollider( ColliderComponent* coll );
		void UnregisterCollider( ColliderComponent* coll );

		void Update( float deltaTime );

	private:
		std::vector<ColliderComponent*> colliders;

		bool collidedLeft( const sf::FloatRect& a, const sf::FloatRect& a_old, const sf::FloatRect& b ) const;
		bool collidedRight( const sf::FloatRect& a, const sf::FloatRect& a_old, const sf::FloatRect& b ) const;
		bool collidedTop( const sf::FloatRect& a, const sf::FloatRect& a_old, const sf::FloatRect& b ) const;
		bool collidedBottom( const sf::FloatRect& a, const sf::FloatRect& a_old, const sf::FloatRect& b ) const;
	};
}