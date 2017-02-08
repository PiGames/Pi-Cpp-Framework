#pragma once

#include <SFML/System/Vector2.hpp>

namespace mc
{
	class Velocity
	{
	public:
		Velocity() : velocity(0, 0) { }

		sf::Vector2f& getVelocity() { return this->velocity; }

		void setVelocity(const sf::Vector2f& v) { this->velocity = v; }

	protected:
		sf::Vector2f velocity;
	};
}