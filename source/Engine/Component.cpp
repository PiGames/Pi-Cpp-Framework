#include "Component.hpp"

namespace pi
{
	void BaseComponent::setName(const std::string & name)
	{
		this->name = name;
	}

	std::string BaseComponent::getName()
	{
		return this->name;
	}
	GameObject * BaseComponent::getGameObject()
	{
		return gameObject;
	}

	BaseComponent::operator bool() const
	{
		return (gameObject != nullptr) ? true:false;
	}
}