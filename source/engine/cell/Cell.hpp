#pragma once


#include "engine/mapObject/MapObject.hpp"
#include "engine/Config.hpp"

namespace pi
{
	class Cell : public MapObject
	{
	public:
		Cell(int id = 0, sf::Texture *texture = nullptr, const std::string& name = "<unnamed Entity>", sf::Vector2f pos = { 0,0 }, std::vector<sf::Vector2i> uPos = { sf::Vector2i(0,0) }, bool collidableFlag = false);

		//Initialization (on the begining of game process)
		static void Init(sf::Vector2i *uWorldSize, sf::Vector2f *celldimensions);

	private:

		const int ID;

		static sf::Vector2i *unitWorldSize;

		static sf::Vector2f *cellDimensions;
	};

}