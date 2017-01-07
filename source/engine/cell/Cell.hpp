#pragma once

#include "engine/map/MapObject.hpp"
#include "engine/Config.hpp"
#include "engine/map/StaticObject.hpp"

namespace pi
{
	class Cell : public StaticObject
	{
	public:
		Cell(int id = 0, sf::Texture *texture = nullptr, const std::string& name = "<unnamed Entity>", const sf::Vector2f& pos = { 0,0 }, std::vector<sf::Vector2i> uPos = { sf::Vector2i(0,0) }, bool collidableFlag = false);

		//Initialization (on the begining of game process)
		static void init(sf::Vector2i *uWorldSize, sf::Vector2f *celldimensions);

	private:

		const int ID;

		static sf::Vector2i *unitWorldSize;

		static sf::Vector2f *cellDimensions;
	};

}