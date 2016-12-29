#pragma once

#include "BoxCollider.hpp"
#include "Rigidbody.hpp"
#include "engine/ecs/GameObject.hpp"
#include "engine/Config.hpp"

namespace pi
{
	namespace physic
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
			std::array<BoxCollider*, constants::physic::collisionDetector::MAX_COLLIDERS> colliders;
		};
	}
}