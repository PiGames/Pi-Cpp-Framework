#pragma once

#include <array>

#include "engine/ecs/Component.hpp"
#include "engine/ecs/GameObject.hpp"
#include "BoxCollider.hpp"

namespace pi
{
	namespace phy
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
			void setPosition(sf::Vector2f&& position);
			// Sets Rigidbody velocity
			void setVeclocity(sf::Vector2f&& velocity);
			// Adds force to current Rigidbody velocity
			void addVelocity(sf::Vector2f&& force);

			void update(float deltaTime);
			// Adds Box Collider to Rigidbody
			// Returns pointer to that Box Collider
			// Also returns nullptr if there is more than 8 colliders attached
			BoxCollider* addBoxCollider(BoxCollider* boxCollider);

			ComponentType getComponentType();

		private:
			const static std::uint8_t MAX_COLLIDERS_COUNT = 8;

			std::array<BoxCollider*, MAX_COLLIDERS_COUNT> colliders;
			sf::Vector2f position;
			sf::Vector2f velocity;
		};
	}
}