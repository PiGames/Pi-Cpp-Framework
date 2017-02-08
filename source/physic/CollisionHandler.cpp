#include "CollisionHandler.hpp"

namespace mc
{
	bool CollisionHandler::collidedLeft(const sf::FloatRect & a, const sf::FloatRect& a_old, const sf::FloatRect & b)
	{
		return a_old.left + a_old.width < b.left &&
			a.left + a.width >= b.left;
	}

	bool CollisionHandler::collidedRight(const sf::FloatRect & a, const sf::FloatRect& a_old, const sf::FloatRect & b)
	{
		return a_old.left >= b.left + b.width &&
			a.left < b.left + b.width;
	}

	bool CollisionHandler::collidedTop(const sf::FloatRect & a, const sf::FloatRect& a_old, const sf::FloatRect & b)
	{
		return a_old.top + a_old.height < b.top &&
			a.top + a.height >= b.top;
	}

	bool CollisionHandler::collidedBottom(const sf::FloatRect & a, const sf::FloatRect& a_old, const sf::FloatRect & b)
	{
		return a_old.top >= b.top + b.height &&
			a.top < b.top + b.height;
	}

	void CollisionHandler::registerCollider(ColliderComponent * coll)
	{
		if (!coll)
		{
			pi::Logger::log("Cannot register collider - collider is not assigned", pi::Logger::MessageType::Error);
			return;
		}

		for (ColliderComponent* c : this->colliders)
			if (c == coll)
			{
				pi::Logger::log("Cannot register collider - found collider with same memory ID (" + std::to_string(reinterpret_cast<std::size_t>(coll)) + ")", pi::Logger::MessageType::Error);
				return;
			}

		this->colliders.push_back(coll);

		pi::Logger::log("Registred collider (" + std::to_string((int)&*coll) + "), total colliders registred: " + std::to_string(this->colliders.size()), pi::Logger::MessageType::Info);
	}

	void CollisionHandler::unregisterCollider(ColliderComponent * coll)
	{
		if (!coll)
		{
			pi::Logger::log("Cannot unregister collider - collider is not assigned", pi::Logger::MessageType::Error);
			return;
		}

		auto result = std::find(this->colliders.begin(), this->colliders.end(), coll);

		if (result != this->colliders.end())
		{
			this->colliders.erase(result);
			pi::Logger::log("Unregistering collider (" + std::to_string(reinterpret_cast<std::size_t>(coll)) + "), total colliders registred: " + std::to_string(this->colliders.size()), pi::Logger::MessageType::Info);

			return;
		}

		pi::Logger::log("Cannot unregister collider - cannot find collider (" + std::to_string(reinterpret_cast<std::size_t>(coll)) + ")", pi::Logger::MessageType::Error);
	}

	void CollisionHandler::update(float deltaTime)
	{
		for (unsigned i = 0; i < colliders.size(); ++i)
			for (unsigned j = 0; j < colliders.size(); ++j)
			{
				if (i == j)
					continue;

				sf::FloatRect& collA = colliders[i]->collisionRect;
				sf::FloatRect collAupdated = collA;
				if (colliders[i]->velocity)
				{
					collAupdated.left += colliders[i]->velocity->getVelocity().x * deltaTime;
					collAupdated.top += colliders[i]->velocity->getVelocity().y * deltaTime;
				}
				sf::FloatRect& collB = colliders[j]->collisionRect;

				if (collAupdated.intersects(collB))
				{
					CollisionInfo::Side sideA = CollisionInfo::None;
					CollisionInfo::Side sideB = CollisionInfo::None;

					if (this->collidedLeft(collAupdated, collA, collB))
					{
						sideA = CollisionInfo::Left;
						sideB = CollisionInfo::Right;
					}
					else if (this->collidedRight(collAupdated, collA, collB))
					{
						sideA = CollisionInfo::Right;
						sideB = CollisionInfo::Left;
					}
					else if (this->collidedTop(collAupdated, collA, collB))
					{
						sideA = CollisionInfo::Top;
						sideB = CollisionInfo::Down;
					}
					else if (this->collidedBottom(collAupdated, collA, collB))
					{
						sideA = CollisionInfo::Down;
						sideB = CollisionInfo::Top;
					}

					if (sideA != CollisionInfo::None && sideB != CollisionInfo::None)
					{
						if (colliders[i]->callback)
							colliders[i]->callback(CollisionInfo(colliders[j], colliders[j]->entity, sideA));
						if (colliders[j]->callback)
							colliders[j]->callback(CollisionInfo(colliders[i], colliders[i]->entity, sideB));
					}
				}
			}
	}
}
