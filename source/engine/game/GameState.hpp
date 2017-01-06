#pragma once
#include <SFML\Graphics\RenderWindow.hpp>

class tiny_state
{
public:
	tiny_state();
	~tiny_state();

	virtual void Initialize(sf::RenderWindow*);
	virtual void Update(sf::RenderWindow*);
	virtual void Render(sf::RenderWindow*);
	virtual void Destroy(sf::RenderWindow*);
};

class GameState
{
public:
	GameState();
	~GameState();

	void SetWindow(sf::RenderWindow*);
	void SetState(tiny_state*);
	void Update();
	void Render();
private:
	sf::RenderWindow* window;
	tiny_state* state;
};

extern GameState gameState;
