#pragma once

#include <SFML\Graphics\RenderWindow.hpp>

#include "engine/ResourceCache.hpp"

class State
{
public:
	State(const std::string& resourceCacheConfig);
	virtual ~State();

	void setWindowPointer(sf::RenderWindow* window);

	virtual void run();
protected:
	unsigned stateID;
};

