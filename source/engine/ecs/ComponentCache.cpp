#include "ComponentCache.hpp"

namespace pi
{
	void ComponentCache::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		for (auto& drawable : this->drawable)
			if (drawable)
				target.draw(*drawable, states);

		for (auto& both : this->both)
			if (both)
				target.draw(*both, states);
	}

	ComponentCache::ComponentCache()
	{
	}

	void ComponentCache::update(float deltaTime)
	{
		for (auto& updatable : this->updatable)
			if (updatable)
				updatable->update(deltaTime);

		for (auto& both : this->both)
			if (both)
				both->update(deltaTime);
	}

}
