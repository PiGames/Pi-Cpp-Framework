#include "GameObject.hpp"

namespace pi
{
	GameObject::GameObject()
	{
		this->name = "<unnamed GameObject>";
		this->unitPosition.emplace_back(0, 0);

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

	std::vector<sf::Vector2i> *GameObject::getPosition()
	{
		return &unitPosition;
	}

	void GameObject::setName(const std::string & name)
	{
		this->name = name;
	}

	void GameObject::setPosition(std::vector<sf::Vector2i> position)
	{
		this->unitPosition = position;
	}
}