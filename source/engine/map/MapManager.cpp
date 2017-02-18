#include "MapManager.hpp"

namespace pi
{
	sf::Vector2i MapManager::unitWorldSize;
	std::vector<Cell> MapManager::surface;
	std::vector<StaticObject> MapManager::staticObjects;
	bool* MapManager::collisionMap;


	void MapManager::createArrays()
	{
		collisionMap = new bool[unitWorldSize.x*unitWorldSize.y];
	}

	void MapManager::SurfaceCollisionMapUpdate()
	{
		for (int i = 0; i < unitWorldSize.x*unitWorldSize.x; ++i)
		{
			collisionMap[i] = surface[i].isCollidable();
		}
	}

	void MapManager::UpdateSingleUnits(StaticObject* object)
	{
		bool flag = object->isCollidable();
		
		for (auto& var : object->getUnitPosition())
			collisionMap[var.y*unitWorldSize.x + var.x] = surface[var.y*unitWorldSize.x + var.x].isCollidable() || flag;
	}

	void MapManager::AddCell(uint8_t number, int id, sf::Texture * texture, const std::string & name, bool collidableFlag)
	{
		surface.push_back(Cell(id, texture, name, sf::Vector2f((number - number / unitWorldSize.x)*constants::cell::CELL_DIMENSIONS.x, (number / unitWorldSize.x)*constants::cell::CELL_DIMENSIONS.y), std::vector<sf::Vector2i>() = { sf::Vector2i(number - number / unitWorldSize.x,number / unitWorldSize.x) }, collidableFlag));
	}

	void MapManager::AddStaticObject(StaticObject staticObject)
	{
		staticObjects.push_back(staticObject);
		UpdateSingleUnits(&staticObject);
	}

	sf::Vector2i & MapManager::GetUnitWorldSize()
	{
		return unitWorldSize;
	}

	std::vector<Cell>& MapManager::GetSurface()
	{
		return surface;
	}

	std::vector<StaticObject>& MapManager::GetStaticObjects()
	{
		return staticObjects;
	}

	bool MapManager::IsCollidableUnit(uint16_t number)
	{
		if (number > unitWorldSize.x*unitWorldSize.y || number < 0)
		{
			Logger::Log(constants::error::mapManager::OUT_OF_MAP, Logger::MessageType::Error, Logger::OutputType::Both);
			return true;
		}
		
		return collisionMap[number];
	}

	bool MapManager::IsCollidableUnit(sf::Vector2i unitPosition)
	{

		if (unitPosition.y*unitWorldSize.x + unitPosition.x > unitWorldSize.x*unitWorldSize.y ||
			unitPosition.x<0 || unitPosition.y<0)
		{
			Logger::Log(constants::error::mapManager::OUT_OF_MAP, Logger::MessageType::Error, Logger::OutputType::Both);
			return true;
		}

		return collisionMap[unitPosition.y*unitWorldSize.x + unitPosition.x];
	}

	std::string MapManager::GetNameDirection(sf::Vector2f speed)
	{
		if (speed.x == 0 && speed.y < 0) return constants::mapManager::nameDirections::NORTH;
		if (speed.x == 0 && speed.y > 0) return constants::mapManager::nameDirections::SOUTH;
		if (speed.x > 0 && speed.y == 0) return constants::mapManager::nameDirections::EAST;
		if (speed.x < 0 && speed.y == 0) return constants::mapManager::nameDirections::WEST;

		if (speed.x < 0 && speed.y < 0) return constants::mapManager::nameDirections::NORTH_WEST;
		if (speed.x > 0 && speed.y < 0) return constants::mapManager::nameDirections::NORTH_EAST;
		if (speed.x > 0 && speed.y > 0) return constants::mapManager::nameDirections::SOUTH_EAST;
		if (speed.x < 0 && speed.y > 0) return constants::mapManager::nameDirections::SOUTH_WEST;
	}

	void MapManager::FillOverlappingToVector(std::vector<sf::Vector2i>* overlapping, sf::Vector2i direction)
	{
		if (direction.x != 0 && direction.y != 0)
		{
			overlapping->emplace_back(direction.x, 0);
			overlapping->emplace_back(0, direction.y);
		}
		else
			overlapping->emplace_back(direction);
	}

	void MapManager::SetUnitWorldSize(sf::Vector2i size)
	{
		unitWorldSize = size;
	}

	void MapManager::FinalizeLogicPartOfMap()
	{
		createArrays();
		SurfaceCollisionMapUpdate();
	}
}

