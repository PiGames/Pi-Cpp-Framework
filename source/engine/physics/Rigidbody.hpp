#pragma once

#include <array>

#include "engine/ecs/Component.hpp"
#include "engine/ecs/GameObject.hpp"
#include "engine/Config.hpp"
#include "BoxCollider.hpp"

namespace pi
{
	namespace physic
	{
		class BoxCollider;

		// Rigidbody Component class
		class Rigidbody final:
			public Component
		{
			friend class CollisionDetector;

		public:
			Rigidbody(GameObject& gameObject);

			// Returns velocity of Rigidbody
			sf::Vector2f getVelocity();

			// Sets Rigidbody position
			void setPosition(const sf::Vector2f& position);
			// Sets Rigidbody velocity
			void setVeclocity(const sf::Vector2f& velocity);
			// Adds force to current Rigidbody velocity
			void addVelocity(const sf::Vector2f& force);

			void update(float deltaTime);
			// Adds Box Collider to Rigidbody
			// Returns pointer to that Box Collider
			// Also returns nullptr if there is more than 8 colliders attached
			BoxCollider* addBoxCollider(BoxCollider* boxCollider);

			ComponentType getComponentType();

		private:
			std::array<BoxCollider*, constants::physic::rigidbody::MAX_COLLIDERS> colliders;
			sf::Vector2f position;
			sf::Vector2f velocity;
		};
	}
}