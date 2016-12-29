#include "MapManager.hpp"

namespace pi
{

	sf::Vector2i MapManager::unitWorldSize;
	Cell* MapManager::surface;
	std::vector<pi::GameObject> MapManager::objects;
	bool* MapManager::collisionMap;


	void MapManager::createArrays()
	{
		surface = new Cell[unitWorldSize.x*unitWorldSize.y];
		collisionMap = new bool[unitWorldSize.x*unitWorldSize.y];
	}

	void MapManager::Init(sf::Vector2i uWorldSize)
	{
		unitWorldSize = uWorldSize;
		createArrays();
		SurfaceCollisionMapUpdate();
	}

	void MapManager::SurfaceCollisionMapUpdate()
	{
		for (size_t i = 0; i < unitWorldSize.x*unitWorldSize.x; i++)
		{
			collisionMap[i] = surface[i].getComponent<PathfinderAttributes>()->getFlag(PathfinderAttributes::FLAGS::COLLIDABLE);
		}
	}

	void MapManager::UpdateSingleUnits(GameObject* object)
	{
		bool flag = object->getComponent<PathfinderAttributes>()->getFlag(PathfinderAttributes::FLAGS::COLLIDABLE);
		
		for (auto& var : object->getUnitPosition())
			collisionMap[var.y*unitWorldSize.x + var.x] = surface[var.y*unitWorldSize.x + var.x].getComponent<PathfinderAttributes>()->getFlag(PathfinderAttributes::FLAGS::COLLIDABLE) && flag;
	}
}

