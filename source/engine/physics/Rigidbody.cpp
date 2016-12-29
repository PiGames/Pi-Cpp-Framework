#include "Rigidbody.hpp"

namespace pi
{
	namespace physic
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

		void Rigidbody::setPosition(const sf::Vector2f& position)
		{
			this->position = position;
		}

		void Rigidbody::setVeclocity(const sf::Vector2f& velocity)
		{
			this->velocity = velocity;
		}

		void Rigidbody::addVelocity(const sf::Vector2f& force)
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
