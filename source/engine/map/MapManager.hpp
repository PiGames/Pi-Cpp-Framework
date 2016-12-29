#pragma once

#include "engine/ecs/GameObject.hpp"
#include "engine/cell/Cell.hpp"
#include "engine/Config.hpp"

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

		static sf::Vector2f cellDimensions;

	public:

		//Initialization (on the begining of game process)
		static void Init(sf::Vector2i uWorldSize, sf::Vector2f celldimensions);

		//Updatesthe whole collision map (Only from surface) | Don't overuse this method!
		static void SurfaceCollisionMapUpdate();

		//Updates units which have represantion on given object 
		static void UpdateSingleUnits(GameObject* object);

		//Returns cell dimensions (in px)
		static sf::Vector2f& GetCellDimensions();

		//Returns unit world size (in units)
		static sf::Vector2i& GetUnitWorldSize();
	};

}