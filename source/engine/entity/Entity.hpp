/*
	Simple Entity-Inheritance system.
	Motivation - ECS is too complex for our need. Or maybe too simple?

	Usage - if you are using entity just simple inherit from Entity class.
*/

#pragma once

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>

namespace pi
{
	// virtual class Entity
	// public methods to override:
	// void update(float dt)
	// void draw(RenderTarget&)
	class Entity : public sf::Drawable
	{
	private:
		// Draws Entity
		// Render Target
		// Render States
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	public:
		Entity(const std::string& name = "<unnamed Entity>");
		virtual ~Entity() = default;

		// Updates Entity
		// deltaTime
		virtual void update(float);

		// Returns reference to Entity name
		std::string& getName();

	protected:
		std::string name;
	};
}