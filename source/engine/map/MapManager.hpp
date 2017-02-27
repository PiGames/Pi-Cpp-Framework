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

		MapManager();
	public:

		//Updatesthe whole collision map (Only from surface) | Don't overuse this method!
		static void SurfaceCollisionMapUpdate();

		//Updates units which have represantion on given object 
		static void UpdateSingleUnits( StaticObject* object );

		static void AddCell( uint8_t number = 0, int id = 0, sf::Texture *texture = nullptr, const std::string& name = "<unnamed Entity>", bool collidableFlag = false );

		static void AddStaticObject( StaticObject staticObject );

		//Returns unit world size (in units)
		static sf::Vector2i& GetUnitWorldSize()
		{
			return unitWorldSize;
		}

		//Returns reference to surface
		static std::vector<Cell> &GetSurface()
		{
			return surface;
		}

		//Returns reference to objects
		static std::vector<StaticObject> &GetStaticObjects()
		{
			return staticObjects;
		}

		//Returns state of map unit
		static bool IsCollidableUnit( uint16_t number );

		//Returns state of map unit
		static bool IsCollidableUnit( sf::Vector2i unitPosition );

		//Returns name direction of moving
		static std::string GetNameDirection( sf::Vector2f speed );

		static void FillOverlappingToVector( std::vector<sf::Vector2i>* overlapping, sf::Vector2i direction );

		static void SetUnitWorldSize( sf::Vector2i size )
		{
			unitWorldSize = size;
		}

		static void FinalizeLogicPartOfMap()
		{
			createArrays();
			SurfaceCollisionMapUpdate();
		}

	private:

		static void createArrays()
		{
			collisionMap = new bool[unitWorldSize.x*unitWorldSize.y];
		}

		static std::vector<Cell> surface;

		static std::vector<StaticObject> staticObjects;

		//true - collidable unit
		//false - not collidable unit
		static bool *collisionMap;

		static sf::Vector2i unitWorldSize;
	};

}