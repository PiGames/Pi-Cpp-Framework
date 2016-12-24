#pragma once

#include <vector>

#include "engine/ecs/Component.hpp"
#include "engine/ecs/GameObject.hpp"


namespace pi
{
	namespace phy
	{
		class Rigidbody;

		class BoxCollider final:
			public UpdatableComponent
		{
			friend class CollisionDetector;

		public:
			BoxCollider(GameObject* gameObject);

			const auto& getCollidersCollidedWith();

			void setOffset(sf::Vector2f offset);
			void setSize(sf::Vector2f size);
			void setRigidbody(Rigidbody * rigidbody);

			void update(float);

		private:
			Rigidbody * rigidbodyAttachedTo;
			sf::Vector2f offset;
			sf::FloatRect rect;

			std::vector<BoxCollider*> collidersCollidedWith;
		};
	}
}