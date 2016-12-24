#include "ComponentCache.hpp"

namespace pi
{
	ComponentCache::ComponentCache()
	{
	}

	void ComponentCache::refresh()
	{
		for (auto& updatable : this->updatableComponents)
			if (updatable && !(*updatable))
				updatable.reset();

		for (auto& drawable : this->drawableComponents)
			if (drawable && !(*drawable))
				drawable.reset();
	}

	void ComponentCache::update(float deltaTime)
	{
		for (auto& updatable : this->updatableComponents)
			if (updatable)
				updatable->update(deltaTime);
	}

	void ComponentCache::draw(sf::RenderTarget & target, sf::RenderStates states)
	{
		for (auto& drawable : this->drawableComponents)
			if (drawable)
				target.draw(*drawable, states);
	}
}