#pragma once

#include "engine/cell/Cell.hpp"
#include "engine/ecs/GameObject.hpp"

class MapController
{
	static Cell *surface;
	static std::vector<pi::GameObject> objects;

	static bool *collisionMap;

	static void createArrays(sf::Vector2i *unitWorldSize);

public:

	//Initialization (on the begining of game process)
	static void Init(sf::Vector2i unitWorldSize);
	
	//Updating the whole collision map | Don't overuse this method!
	static void CompleteCollisionMapUpdate();
};
