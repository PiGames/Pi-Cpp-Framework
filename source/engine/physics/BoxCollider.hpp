#pragma once

#include <vector>

#include "Rigidbody.hpp"
#include "engine/ecs/Component.hpp"
#include "engine/ecs/GameObject.hpp"


namespace pi
{
	namespace phy
	{
		class Rigidbody;

		class BoxCollider final:
			public Component
		{
			friend class CollisionDetector;

		public:
			BoxCollider(GameObject& gameObject);

			const auto& getCollidersCollidedWith();

			void setOffset(sf::Vector2f offset);
			void setSize(sf::Vector2f size);
			void setRigidbody(Rigidbody * rigidbody);

			void update(float);

			ComponentType getComponentType();

		private:
			Rigidbody * rigidbodyAttachedTo;
			sf::Vector2f offset;
			sf::FloatRect rect;

			std::vector<BoxCollider*> collidersCollidedWith;
		};
	}
}