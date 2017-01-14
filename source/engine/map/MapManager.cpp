#include "MapManager.hpp"

namespace pi
{
	sf::Vector2f MapManager::cellDimensions;
	sf::Vector2i MapManager::unitWorldSize;
	std::vector<Cell> MapManager::surface;
	std::vector<MapObject> MapManager::objects;
	bool* MapManager::collisionMap;


	void MapManager::createArrays()
	{
		collisionMap = new bool[unitWorldSize.x*unitWorldSize.y];
	}

	void MapManager::init(sf::Vector2i uWorldSize, const sf::Vector2f&  celldimensions)
	{
		unitWorldSize = uWorldSize;
		cellDimensions = celldimensions;
		createArrays();
		surfaceCollisionMapUpdate();
	}

	void MapManager::surfaceCollisionMapUpdate()
	{
		for (int i = 0; i < unitWorldSize.x*unitWorldSize.x; ++i)
		{
			collisionMap[i] = surface[i].isCollidable();
		}
	}

	void MapManager::updateSingleUnits(StaticObject* object)
	{
		bool flag = object->isCollidable();
		
		for (auto& var : object->getUnitPosition())
			collisionMap[var.y*unitWorldSize.x + var.x] = surface[var.y*unitWorldSize.x + var.x].isCollidable() && flag;
	}

	void MapManager::addCell(uint8_t number, int id, sf::Texture * texture, const std::string & name, bool collidableFlag)
	{
		surface.push_back(Cell(id, texture, name, sf::Vector2f((number - number / unitWorldSize.x)*cellDimensions.x, (number / unitWorldSize.x)*cellDimensions.y), std::vector<sf::Vector2i>() = { sf::Vector2i(number - number / unitWorldSize.x,number / unitWorldSize.x) }, collidableFlag));
	}

	sf::Vector2f & MapManager::getCellDimensions()
	{
		return cellDimensions;
	}
	sf::Vector2i & MapManager::getUnitWorldSize()
	{
		return unitWorldSize;
	}

	std::vector<Cell>& MapManager::getSurface()
	{
		return surface;
	}

	std::vector<MapObject>& MapManager::getMapObjects()
	{
		return objects;
	}

	bool MapManager::isCollidableUnit(uint16_t number)
	{
		if (number > unitWorldSize.x*unitWorldSize.y || number < 0)
		{
			Logger::log(constants::error::mapManager::OUT_OF_MAP, Logger::MessageType::Error, Logger::OutputType::Both);
			return true;
		}
		
		return collisionMap[number];
	}

	bool MapManager::isCollidableUnit(sf::Vector2i unitPosition)
	{

		if (unitPosition.y*unitWorldSize.x + unitPosition.x > unitWorldSize.x*unitWorldSize.y ||
			unitPosition.x<0 || unitPosition.y<0)
		{
			Logger::log(constants::error::mapManager::OUT_OF_MAP, Logger::MessageType::Error, Logger::OutputType::Both);
			return true;
		}

		return collisionMap[unitPosition.y*unitWorldSize.x + unitPosition.x];
	}
}

