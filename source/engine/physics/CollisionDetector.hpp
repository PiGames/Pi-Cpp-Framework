#pragma once

#include "BoxCollider.hpp"
#include "Rigidbody.hpp"
#include "engine/ecs/GameObject.hpp"

namespace pi
{
	namespace phy
	{
		class CollisionDetector final
		{
		public:
			CollisionDetector();

			BoxCollider* addBoxCollider(BoxCollider* boxCollider);

			void update(float deltaTime);

		private:
			const static std::uint16_t MAX_COLLIDERS_COUNT = 512;

			std::array<BoxCollider*, MAX_COLLIDERS_COUNT> colliders;
		};
	}
}