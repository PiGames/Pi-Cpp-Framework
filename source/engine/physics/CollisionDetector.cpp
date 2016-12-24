#include "CollisionDetector.hpp"

namespace pi
{
	namespace phy
	{
		CollisionDetector::CollisionDetector()
		{
			this->colliders.fill(nullptr);
		}

		BoxCollider * CollisionDetector::addBoxCollider(BoxCollider * boxCollider)
		{
			for(auto* ptr : this->colliders)
				if (ptr == nullptr)
				{
					ptr = boxCollider;
					
					return boxCollider;
				}

			return nullptr;
		}

		void CollisionDetector::refresh()
		{
			for (auto* ptr : this->colliders)
				if (ptr && !(*ptr))
					ptr = nullptr;
		}

		void CollisionDetector::update(float deltaTime)
		{
			std::uint16_t loopCounter = 0;

			// First clean colliders
			for (auto* ptr : this->colliders)
				if(ptr != nullptr)
					ptr->collidersCollidedWith.clear();

			//then we loop thru whole colliders
			for (auto* ptr : this->colliders)
			{
				//skip if nullptr
				if (ptr == nullptr)
					continue;

				// get its rigidbody
				auto rb = ptr->rigidbodyAttachedTo;

				// loop thru rigidbody colliders
				for(auto collRB : rb->colliders)
					// loop thru all colliders
					for (auto collB : this->colliders)
					{
						if (collRB == nullptr)
							break;
						if (collB == nullptr)
							continue;
						if (collB->rigidbodyAttachedTo == rb)
							continue;

						auto rectAnext = collRB->rect;
						auto rectBnext = collB->rect;

						rectAnext.left += rb->velocity.x * deltaTime;
						rectAnext.top += rb->velocity.y * deltaTime;
					
						rectBnext.left += collB->rigidbodyAttachedTo->velocity.x * deltaTime;
						rectBnext.top += collB->rigidbodyAttachedTo->velocity.y * deltaTime;

						if (rectAnext.intersects(rectBnext))
						{
							collRB->collidersCollidedWith.push_back(collB);
							collB->collidersCollidedWith.push_back(collRB);
						}
					}
			}
		}
	}
}

