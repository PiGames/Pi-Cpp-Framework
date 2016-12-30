#pragma once

#include <vector>

#include "Rigidbody.hpp"
#include "engine/Config.hpp"
#include "engine/ecs/Component.hpp"
#include "engine/ecs/GameObject.hpp"


namespace pi
{
	namespace physic
	{
		class Rigidbody;

		// Box Collider Component
		// Attach it to RigidBody Component!
		class BoxCollider final:
			public Component
		{
			friend class CollisionDetector;

		public:
			BoxCollider(GameObject& gameObject);

			// Returns const std::vector of pointers to BoxColliders that collided with this Collider
			const auto& getCollidersCollidedWith();
			// Returns offset relative to RigidBody position
			void setOffset(const sf::Vector2f& offset);
			// Returns Collider size
			void setSize(const sf::Vector2f& size);
			// Returns Rigidbody that this Collider is attached
			void setRigidbody(Rigidbody * rigidbody);
			// Adds callback (function) if collider collided
			void addCallback(void(*callback)(BoxCollider& other));

			void update(float);

			ComponentType getComponentType();

		private:
			Rigidbody * rigidbodyAttachedTo;
			sf::Vector2f offset;
			sf::FloatRect rect;

			std::vector<BoxCollider*> collidersCollidedWith;
			std::array<void(*)(BoxCollider& other), constants::physic::boxCollider::MAX_CALLBACKS> callbacks;

		};
	}
}