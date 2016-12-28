#pragma once

#include "engine/cell/Cell.hpp"
#include "engine/ecs/GameObject.hpp"

namespace pi
{
	class MapManager
	{
		static Cell *surface;
		static std::vector<GameObject> objects;

		//true - collidable unit
		//false - not collidable unit
		static bool *collisionMap;

		static void createArrays();

		static sf::Vector2i unitWorldSize;

	public:

		//Initialization (on the begining of game process)
		static void Init(sf::Vector2i uWorldSize);

		//Updating the whole collision map | Don't overuse this method!
		static void CompleteCollisionMapUpdate();

		//Updating 1 unit of collision map
		static void UpdateSingleUnits(GameObject* object);
	};

}