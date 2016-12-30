#pragma once

#include "SFML\System\Vector2.hpp"
#include "engine\entity\Entity.hpp"
#include <vector>

namespace pi
{
	class MapObject : public Entity
	{
	public:
		MapObject(const std::string& name = "<unnamed Entity>", sf::Vector2f pos = { 0,0 }, std::vector<sf::Vector2i> uPos = { sf::Vector2i(0,0) });

		sf::Vector2f& GetPosition();

		std::vector<sf::Vector2i>& GetUnitPosition();

	private:

		//position (in px)
		sf::Vector2f position; 
		
		//vector of unit position (in unit system)
		std::vector<sf::Vector2i> unitPosition;
	};
}
