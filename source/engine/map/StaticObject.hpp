#pragma once

#include <SFML/System/Vector2.hpp>
#include "CollidableObject.hpp"
#include <vector>

namespace pi
{
	class StaticObject : public CollidableObject
	{
	public:

		StaticObject(std::vector<sf::Vector2i> uPos = { sf::Vector2i(0,0) }, bool collidableFlag = false);
		~StaticObject();

		//Returns vector of unit position (in unit system)
		std::vector<sf::Vector2i>& getUnitPosition();

	protected:

		//vector of unit position (in unit system)
		std::vector<sf::Vector2i> unitPosition;
	};
}