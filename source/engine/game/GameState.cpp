#include "GameState.hpp"


tiny_state::tiny_state()
{
}

tiny_state::~tiny_state()
{
}

void tiny_state::Initialize(sf::RenderWindow *)
{
}

void tiny_state::Update(sf::RenderWindow *)
{
}

void tiny_state::Render(sf::RenderWindow *)
{
}

void tiny_state::Destroy(sf::RenderWindow *)
{
}

GameState::GameState()
{
	this->state = NULL;
}


GameState::~GameState()
{
	this->state->Destroy(window);
}

void GameState::SetWindow(sf::RenderWindow *window)
{
	this->window = window;
}

void GameState::SetState(tiny_state *state)
{
	if (this->state != NULL)
	{
		this->state->Destroy(this->window);
	}

	delete this->state;
	this->state = state;

	if (this->state != NULL)
	{
		this->state->Initialize(window);
	}
}

void GameState::Update()
{
	if (this->state != NULL)
	{
		this->state->Update(this->window);
	}
}

void GameState::Render()
{
	if (this->state != NULL)
	{
		this->state->Render(this->window);
	}
}
