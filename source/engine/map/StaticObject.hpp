// Created by: mvxxx
#pragma once

#include <vector>

#include <SFML/System/Vector2.hpp>

#include "CollidableObject.hpp"
#include "MapObject.hpp"

namespace pi
{
	//StaticObject class
	//Represents MapObject which is not able to move
	//It can be collidable but you can off it by object.setCollidable(false)
	class StaticObject : public MapObject, public CollidableObject
	{
	public:

		StaticObject(const std::string& name = "<unnamed Entity>", const sf::Vector2f& pos = { 0,0 }, std::vector<sf::Vector2i> uPos = { sf::Vector2i(0,0) }, bool collidableFlag = false);
		~StaticObject();

		//Returns vector of unit position (in unit system)
		std::vector<sf::Vector2i>& getUnitPosition();

	protected:

		//vector of unit position (in unit system)
		std::vector<sf::Vector2i> unitPosition;
	};
}