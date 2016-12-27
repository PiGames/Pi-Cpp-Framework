#include "ComponentCache.hpp"

namespace pi
{
	void ComponentCache::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		for (auto& drawable : this->drawable)
			if (drawable)
				target.draw(*drawable, states);
	}

	ComponentCache::ComponentCache()
	{
	}

	void ComponentCache::update(float deltaTime)
	{
		for (auto& updatable : this->updatable)
			if (updatable)
				updatable->update(deltaTime);
	}

}
