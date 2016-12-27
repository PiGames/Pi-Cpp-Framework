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

		class Rigidbody final:
			public Component
		{
			friend class CollisionDetector;

		public:
			Rigidbody(GameObject& gameObject);

			sf::Vector2f getVelocity();

			void setPosition(sf::Vector2f position);
			void setVeclocity(sf::Vector2f velocity);
			void addVelocity(sf::Vector2f force);

			void update(float deltaTime);
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