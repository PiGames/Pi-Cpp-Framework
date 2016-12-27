#pragma once

#include "BoxCollider.hpp"
#include "Rigidbody.hpp"
#include "engine/ecs/GameObject.hpp"

namespace pi
{
	namespace phy
	{
		// Collision Detector class
		class CollisionDetector final
		{
		public:
			CollisionDetector();
			
			// Adds Box Collider to internal vector and returns pointer to it
			// Also returns nullptr if there is more that 512 colliders
			BoxCollider* addBoxCollider(BoxCollider* boxCollider);

			void update(float deltaTime);

		private:
			const static std::uint16_t MAX_COLLIDERS_COUNT = 512;

			std::array<BoxCollider*, MAX_COLLIDERS_COUNT> colliders;
		};
	}
}