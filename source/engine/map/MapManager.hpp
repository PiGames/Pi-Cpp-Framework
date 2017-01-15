#pragma once

#include <memory>
#include <vector>

#include <SFML/System/Vector2.hpp>

#include "engine/cell/Cell.hpp"
#include "engine/Config.hpp"
#include "engine/map/StaticObject.hpp"
#include "engine/Logger.hpp"

namespace pi
{
	class MapManager
	{

		static void createArrays();

	public:
		MapManager() = delete;

		//Initialization (on the begining of game process)
		static void init(sf::Vector2i uWorldSize, const sf::Vector2f& celldimensions);

		//Updatesthe whole collision map (Only from surface) | Don't overuse this method!
		static void surfaceCollisionMapUpdate();

		//Updates units which have represantion on given object 
		static void updateSingleUnits(StaticObject* object);

		static void addCell(uint8_t number = 0, int id = 0, sf::Texture *texture = nullptr, const std::string& name = "<unnamed Entity>", bool collidableFlag = false);

		static void addStaticObject(StaticObject staticObject);

		//Returns cell dimensions (in px)
		static sf::Vector2f& getCellDimensions();

		//Returns unit world size (in units)
		static sf::Vector2i& getUnitWorldSize();

		//Returns reference to surface
		static std::vector<Cell> &getSurface();

		//Returns reference to objects
		static std::vector<StaticObject> &getStaticObjects();

		//Returns state of map unit
		static bool isCollidableUnit(uint16_t number);

		//Returns state of map unit
		static bool isCollidableUnit(sf::Vector2i unitPosition);

	private:

		static std::vector<Cell> surface;

		static std::vector<StaticObject> staticObjects;

		//true - collidable unit
		//false - not collidable unit
		static bool *collisionMap;

		static sf::Vector2i unitWorldSize;

		static sf::Vector2f cellDimensions;
	};

}