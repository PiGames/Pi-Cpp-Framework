#include "MapManager.hpp"

namespace pi
{
	Cell* MapManager::surface;
	std::vector<pi::GameObject> MapManager::objects;
	bool* MapManager::collisionMap;


	void MapManager::createArrays(sf::Vector2i *unitWorldSize)
	{
		surface = new Cell[unitWorldSize->x*unitWorldSize->y];
		collisionMap = new bool[unitWorldSize->x*unitWorldSize->y];
	}

	void MapManager::Init(sf::Vector2i unitWorldSize)
	{
		createArrays(&unitWorldSize);
		CompleteCollisionMapUpdate();
	}

	void MapManager::CompleteCollisionMapUpdate() { }
}

