#include "Entity.hpp"

namespace pi
{
	Entity::Entity(const std::string & name) :
		name(name)
	{
	}
	void Entity::update(float)
	{
	}


	void Entity::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
	}

	std::string& Entity::getName()
	{
		return this->name;
	}
}

