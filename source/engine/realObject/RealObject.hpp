#pragma once

#include <vector>
#include <SFML/System/Vector2.hpp>

namespace pi
{
	class RealObject
	{
		std::vector<sf::Vector2i> unitPosition;

	public:
		//unitPos(sf::Vector2i(0,0))
		RealObject(std::vector<sf::Vector2i> unitPos = std::vector<sf::Vector2i>{ sf::Vector2i(0,0) });

		//Returns vector of unit position
		std::vector<sf::Vector2i> GetUnitPosition();

		//Sets unit position
		void SetUnitPosition(std::vector<sf::Vector2i> unitPos);
	};
}
