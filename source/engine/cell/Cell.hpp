// Created by: mvxxx
#pragma once

#include "engine/map/MapObject.hpp"
#include "engine/Config.hpp"
#include "engine/map/StaticObject.hpp"

namespace pi
{
	//Cell class
	//Represents a single cell on the map
	class Cell : public StaticObject
	{
	public:
		Cell(int id = 0, sf::Texture *texture = nullptr, const std::string& name = "<unnamed Entity>", const sf::Vector2f& pos = { 0,0 }, std::vector<sf::Vector2i> uPos = { sf::Vector2i(0,0) }, bool collidableFlag = false);

		//Returns ID of cell
		int16_t getID();

	private:

		const int16_t ID;
	};

}