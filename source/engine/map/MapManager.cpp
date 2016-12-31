#include "MapManager.hpp"

namespace pi
{
	sf::Vector2f MapManager::cellDimensions;
	sf::Vector2i MapManager::unitWorldSize;
	std::vector<Cell> MapManager::surface;
	std::vector<MapObject> MapManager::objects;
	bool* MapManager::collisionMap;


	void MapManager::createArrays()
	{
		collisionMap = new bool[unitWorldSize.x*unitWorldSize.y];
	}

	void MapManager::Init(sf::Vector2i uWorldSize, const sf::Vector2f&  celldimensions)
	{
		unitWorldSize = uWorldSize;
		cellDimensions = celldimensions;
		createArrays();
		SurfaceCollisionMapUpdate();
	}

	void MapManager::SurfaceCollisionMapUpdate()
	{
		for (int i = 0; i < unitWorldSize.x*unitWorldSize.x; i++)
		{
			collisionMap[i] = surface[i].IsCollidable();
		}
	}

	void MapManager::UpdateSingleUnits(MapObject* object)
	{
		bool flag = object->IsCollidable();
		
		for (auto& var : object->GetUnitPosition())
			collisionMap[var.y*unitWorldSize.x + var.x] = surface[var.y*unitWorldSize.x + var.x].IsCollidable() && flag;
	}

	void MapManager::AddCell(uint8_t number, int id, sf::Texture * texture, const std::string & name, bool collidableFlag)
	{
		surface.push_back(Cell(id, texture, name, sf::Vector2f((number - number / unitWorldSize.x)*cellDimensions.x, (number / unitWorldSize.x)*cellDimensions.y), std::vector<sf::Vector2i>() = { sf::Vector2i(number - number / unitWorldSize.x,number / unitWorldSize.x) }, collidableFlag));
	}

	sf::Vector2f & MapManager::GetCellDimensions()
	{
		return cellDimensions;
	}
	sf::Vector2i & MapManager::GetUnitWorldSize()
	{
		return unitWorldSize;
	}
}

