#include "GameObject.hpp"

namespace pi
{
	GameObject::GameObject()
	{
		this->name = "<unnamed GameObject>";
		this->position = sf::Vector2f(0, 0);
	}

	std::string& GameObject::getName()
	{
		return this->name;
	}

	sf::Vector2f& GameObject::getPosition()
	{
		return this->position;
	}

	void GameObject::setName(const std::string& name)
	{
		this->name = name;
	}

	void GameObject::setPosition(const sf::Vector2f& position)
	{
		this->position = position;
	}
}

