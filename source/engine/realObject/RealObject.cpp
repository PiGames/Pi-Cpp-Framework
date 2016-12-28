#include "RealObject.hpp"

namespace pi 
{
	RealObject::RealObject(std::vector<sf::Vector2i> unitPos) : unitPosition(unitPos)
	{
	}


	std::vector<sf::Vector2i> RealObject::GetUnitPosition()
	{
		return unitPosition;
	}

	void RealObject::SetUnitPosition(std::vector<sf::Vector2i> unitPos)
	{
		unitPosition = unitPos;
	}

}
