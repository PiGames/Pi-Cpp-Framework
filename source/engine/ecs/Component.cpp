#include "Component.hpp"

namespace pi
{
	void Component::update(float)
	{
	}

	void Component::draw(sf::RenderTarget &, sf::RenderStates) const
	{
	}

	Component::~Component()
	{
	}

	auto& Component::getGameObject()
	{
		return this->gameObject;
	}

	auto& Component::getName()
	{
		return this->name;
	}

	std::type_index Component::getUniqueType()
	{
		return this->uniqueType;
	}

	void Component::setName(std::string && name)
	{
		this->name = name;
	}
}

