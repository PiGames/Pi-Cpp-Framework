#include "MapManager.hpp"

Cell* MapController::surface;
std::vector<pi::GameObject> MapController::objects;
bool* MapController::collisionMap;


void MapController::createArrays(sf::Vector2i *unitWorldSize)
{
	surface = new Cell[unitWorldSize->x*unitWorldSize->y];
	collisionMap = new bool[unitWorldSize->x*unitWorldSize->y];
}

void MapController::Init(sf::Vector2i unitWorldSize)
{
	createArrays(&unitWorldSize);
	CompleteCollisionMapUpdate();
}

void MapController::CompleteCollisionMapUpdate() { }