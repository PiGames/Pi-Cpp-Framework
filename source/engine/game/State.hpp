#pragma once
#include <SFML\Graphics\RenderWindow.hpp>

class State
{
public:
	State();
	~State();

	virtual void run();
protected:
	unsigned stateID;
};

