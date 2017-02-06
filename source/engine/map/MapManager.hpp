// Created by: mvxxx
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
	//class MapManager
	//It administers a static part of map (surface <=> cells && other StaticObjects)
	class MapManager
	{
		friend class MapRenderer;


		static void createArrays();

		MapManager();

	public:
		//Initialization (on the begining of game process)
		static void init(sf::Vector2i uWorldSize);

		//Updatesthe whole collision map (Only from surface) | Don't overuse this method!
		static void surfaceCollisionMapUpdate();

		//Updates units which have represantion on given object 
		static void updateSingleUnits(StaticObject* object);

		static void addCell(uint8_t number = 0, int id = 0, sf::Texture *texture = nullptr, const std::string& name = "<unnamed Entity>", bool collidableFlag = false);

		static void addStaticObject(StaticObject staticObject);

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

		//Returns name direction of moving
		static std::string getNameDirection(sf::Vector2f speed);

		static void fillOverlappingToVector(std::vector<sf::Vector2i>* overlapping, sf::Vector2i direction);

	private:

		static std::vector<Cell> surface;

		static std::vector<StaticObject> staticObjects;

		//true - collidable unit
		//false - not collidable unit
		static bool *collisionMap;

		static sf::Vector2i unitWorldSize;
	};

}