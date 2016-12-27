#pragma once

#include <vector>
#include <SFML/System/Vector2.hpp>

namespace pi
{
	class RealObject
	{
		std::vector<sf::Vector2i> unitPosition;

		bool collideable;

	public:
		//Constructor | dafault: flag(false), unitPos(sf::Vector2i(0,0))
		RealObject(bool collisionFlag = false, std::vector<sf::Vector2i> unitPos = std::vector<sf::Vector2i>{ sf::Vector2i(0,0) });

		//Returns true if object is collideable
		bool IsCollideable();

		//Sets collideable
		void SetCollideableFlag(bool type);

		//Returns vector of unit position
		std::vector<sf::Vector2i> GetUnitPosition();

		//Sets unit position
		void SetUnitPosition(std::vector<sf::Vector2i> unitPos);
	};
}
