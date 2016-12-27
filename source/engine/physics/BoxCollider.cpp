#include "BoxCollider.hpp"

namespace pi
{
	namespace phy
	{
		BoxCollider::BoxCollider(GameObject& gameObject) : Component(gameObject, this)
		{
			this->rigidbodyAttachedTo = gameObject.getComponent<Rigidbody>();
			this->offset = sf::Vector2f(0, 0);
			this->rect = sf::FloatRect(gameObject.getPosition().x, gameObject.getPosition().y, 0, 0);
		}

		const auto & BoxCollider::getCollidersCollidedWith()
		{
			return this->collidersCollidedWith;
		}

		void BoxCollider::setOffset(sf::Vector2f&& offset)
		{
			this->offset = offset;

			this->rect.left = this->offset.x;
			this->rect.top = this->offset.y;
		}

		void BoxCollider::setSize(sf::Vector2f&& size)
		{
			this->rect.width = size.x;
			this->rect.height = size.y;
		}

		void BoxCollider::setRigidbody(Rigidbody * rigidbody)
		{
			this->rigidbodyAttachedTo = rigidbody;
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

