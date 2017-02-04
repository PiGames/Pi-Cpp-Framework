// Created by: Condzi
#pragma once

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>

namespace pi
{
	// virtual class Entity
	// Inherit from it to make entity.
	// public methods to override:
	// void update(float time)
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