#include "Rigidbody.hpp"

namespace pi
{
	namespace phy
	{
		Rigidbody::Rigidbody(GameObject& gameObject) : Component(gameObject, this)
		{
			this->colliders.fill(nullptr);
			this->position = gameObject.getPosition();
			this->velocity = sf::Vector2f(0, 0);
		}

		sf::Vector2f Rigidbody::getVelocity()
		{
			return this->velocity;
		}

		void Rigidbody::setPosition(sf::Vector2f position)
		{
			this->position = position;
		}

		void Rigidbody::setVeclocity(sf::Vector2f velocity)
		{
			this->velocity = velocity;
		}

		void Rigidbody::addVelocity(sf::Vector2f force)
		{
			this->velocity += force;
		}

		void Rigidbody::update(float deltaTime)
		{
			this->gameObject.setPosition(this->position + velocity * deltaTime);
		}

		BoxCollider * Rigidbody::addBoxCollider(BoxCollider * boxCollider)
		{
			for (auto* ptr : this->colliders)
				if (ptr == nullptr)
				{
					ptr = boxCollider;

					return boxCollider;
				}

			return nullptr;
		}

		ComponentType Rigidbody::getComponentType()
		{
			return ComponentType::Updatable;
		}
	}
}
