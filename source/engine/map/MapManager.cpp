#include "MapManager.hpp"

namespace pi
{
	sf::Vector2f MapManager::cellDimensions;
	sf::Vector2i MapManager::unitWorldSize;
	Cell* MapManager::surface;
	std::vector<MapObject> MapManager::objects;
	bool* MapManager::collisionMap;


	void MapManager::createArrays()
	{
		surface = new Cell[unitWorldSize.x*unitWorldSize.y];
		collisionMap = new bool[unitWorldSize.x*unitWorldSize.y];
	}

	void MapManager::Init(sf::Vector2i uWorldSize, const sf::Vector2f& celldimensions)
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

	sf::Vector2f & MapManager::GetCellDimensions()
	{
		return cellDimensions;
	}
	sf::Vector2i & MapManager::GetUnitWorldSize()
	{
		return unitWorldSize;
	}
}

