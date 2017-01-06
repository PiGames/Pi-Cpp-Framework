#pragma once
#include "../ResourceCache.hpp"
#include <SFML\Graphics\RenderWindow.hpp>

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

