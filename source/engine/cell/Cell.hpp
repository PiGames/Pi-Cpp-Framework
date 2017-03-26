// Created by: mvxxx
#pragma once

#include "engine/map/MapObject.hpp"
#include "engine/Config.hpp"
#include "engine/map/StaticObject.hpp"

namespace pi
{
	//Cell class
	//Represents a single cell on the map
	class Cell
	{
	public:
		Cell( uint16_t id = 0, const sf::Vector2f& pos = { 0, 0 }, std::vector<sf::Vector2i> uPos = { sf::Vector2i( 0, 0 ) }, bool collidableFlag = false );

		//Returns ID of cell
		uint16_t GetID() const
		{
			return this->ID;
		}
		sf::Vector2f GetPosition() const
		{
			return this->position;
		}
		std::vector<sf::Vector2i> GetUnitPosition() const
		{
			return this->unitPosition;
		}
		bool GetCollidableFlag() const
		{
			return this->isCollidable;
		}

	private:
		const uint16_t ID;
		sf::Vector2f position;
		std::vector<sf::Vector2i> unitPosition;
		bool isCollidable;
	};

}