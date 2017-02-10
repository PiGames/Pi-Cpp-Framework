#pragma once

#include <vector>
#include <string>

#include "engine/Logger.hpp"

#include "ColliderComponent.hpp"

namespace mc
{
	class CollisionHandler final
	{
	private:
		bool collidedLeft(const sf::FloatRect& a, const sf::FloatRect& a_old, const sf::FloatRect& b);
		bool collidedRight(const sf::FloatRect& a, const sf::FloatRect& a_old, const sf::FloatRect& b);
		bool collidedTop(const sf::FloatRect& a, const sf::FloatRect& a_old, const sf::FloatRect& b);
		bool collidedBottom(const sf::FloatRect& a, const sf::FloatRect& a_old, const sf::FloatRect& b);

	public:
		CollisionHandler() {}

		void registerCollider(ColliderComponent* coll);
		void unregisterCollider(ColliderComponent* coll);

		void update(float deltaTime);

	private:
		std::vector<ColliderComponent*> colliders;
	};
}