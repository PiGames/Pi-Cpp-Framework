#include "GameObject.hpp"

namespace pi
{
	GameObject::GameObject()
	{
		this->name = "<unnamed GameObject>";

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

	void GameObject::setName(const std::string & name)
	{
		this->name = name;
	}
}