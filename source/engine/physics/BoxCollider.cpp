#include "BoxCollider.hpp"

namespace pi
{
	namespace physic
	{
		BoxCollider::BoxCollider(GameObject& gameObject) : Component(gameObject, this)
		{
			this->rigidbodyAttachedTo = gameObject.getComponent<Rigidbody>();
			this->offset = sf::Vector2f(0, 0);
			this->rect = sf::FloatRect(gameObject.getPosition().x, gameObject.getPosition().y, 0, 0);
	
			callbacks.fill(nullptr);
		}

		const auto & BoxCollider::getCollidersCollidedWith()
		{
			return this->collidersCollidedWith;
		}

		void BoxCollider::setOffset(const sf::Vector2f& offset)
		{
			this->offset = offset;

			this->rect.left = this->offset.x;
			this->rect.top = this->offset.y;
		}

		void BoxCollider::setSize(const sf::Vector2f& size)
		{
			this->rect.width = size.x;
			this->rect.height = size.y;
		}

		void BoxCollider::setRigidbody(Rigidbody * rigidbody)
		{
			this->rigidbodyAttachedTo = rigidbody;
		}

		void BoxCollider::addCallback(void(*callback)(BoxCollider &other))
		{
			for (auto& call : this->callbacks)
				if (call == nullptr)
					call = callback;
		}


		void BoxCollider::update(float)
		{
			this->rect.left = this->gameObject.getPosition().x + this->offset.x;
			this->rect.top = this->gameObject.getPosition().y + this->offset.y;
		}

		ComponentType BoxCollider::getComponentType()
		{
			return ComponentType::Updatable;
		}
	}
}

