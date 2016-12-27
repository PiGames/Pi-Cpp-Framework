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

	void GameObject::setName(std::string && name)
	{
		this->name = name;
	}

	void GameObject::setPosition(sf::Vector2f && position)
	{
		this->position = position;
	}
}

