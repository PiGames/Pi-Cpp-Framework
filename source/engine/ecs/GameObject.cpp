#include "GameObject.hpp"

namespace pi
{
	GameObject::GameObject()
	{
		this->name = "<unnamed GameObject>";
		this->position = sf::Vector2f(0, 0);

		updatableComponents.fill(nullptr);
		drawableComponents.fill(nullptr);
	}

	GameObject::~GameObject()
	{
		for (auto* drawable : this->drawableComponents)
			drawable->gameObject = nullptr;

		for (auto* updatable : this->updatableComponents)
			updatable->gameObject = nullptr;
	}

	std::string GameObject::getName()
	{
		return this->name;
	}

	sf::Vector2f GameObject::getPosition()
	{
		return this->position;
	}

	void GameObject::setName(const std::string & name)
	{
		this->name = name;
	}

	void GameObject::setPosition(sf::Vector2f position)
	{
		this->position = position;
	}
}