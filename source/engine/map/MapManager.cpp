#include "MapManager.hpp"

namespace pi
{
	sf::Vector2i MapManager::unitWorldSize;
	std::vector<Cell> MapManager::surface;
	std::vector<StaticObject> MapManager::staticObjects;
	bool* MapManager::collisionMap;


	void MapManager::SurfaceCollisionMapUpdate()
	{
		for ( int i = 0; i < unitWorldSize.x*unitWorldSize.y; ++i )
		{
			collisionMap[i] = surface[i].IsCollidable();
		}
	}

	void MapManager::UpdateSingleUnits( StaticObject* object )
	{
		bool flag = object->IsCollidable();

		for ( const auto& var : object->GetUnitPosition() )
			collisionMap[var.y * unitWorldSize.x + var.x] = surface[var.y * unitWorldSize.x + var.x].IsCollidable() || flag;
	}

	void MapManager::AddCell( std::weak_ptr<sf::Texture> texture, uint8_t number, int id, const std::string & name, bool collidableFlag )
	{
		if ( unitWorldSize.x == 0 || unitWorldSize.y == 0 )
			pi::Logger::Log( "World size cannot be zero", pi::Logger::MessageType::Error );
		else
			surface.push_back( Cell( texture, id, name, sf::Vector2f( ( number - number / unitWorldSize.x )*constants::cell::CELL_DIMENSIONS.x, ( number / unitWorldSize.x )*constants::cell::CELL_DIMENSIONS.y ), std::vector<sf::Vector2i>() = { sf::Vector2i( number - number / unitWorldSize.x, number / unitWorldSize.x ) }, collidableFlag ) );
	}

	void MapManager::AddStaticObject( StaticObject& staticObject )
	{
		staticObjects.push_back( staticObject );
		UpdateSingleUnits( &staticObject );
	}

	bool MapManager::IsCollidableUnit( uint16_t number )
	{
		if ( number > unitWorldSize.x*unitWorldSize.y || number < 0 )
		{
			Logger::Log( constants::error::mapManager::OUT_OF_MAP, Logger::MessageType::Error, Logger::OutputType::Both );
			return true;
		}

		return collisionMap[number];
	}

	bool MapManager::IsCollidableUnit( sf::Vector2i& unitPosition )
	{

		if ( unitPosition.y*unitWorldSize.x + unitPosition.x > unitWorldSize.x*unitWorldSize.y ||
			unitPosition.x < 0 || unitPosition.y < 0 )
		{
			Logger::Log( constants::error::mapManager::OUT_OF_MAP, Logger::MessageType::Error, Logger::OutputType::Both );
			return true;
		}

		return collisionMap[unitPosition.y*unitWorldSize.x + unitPosition.x];
	}



	void MapManager::FillOverlappingToVector( std::vector<sf::Vector2i>* overlapping, sf::Vector2i& direction )
	{
		if ( direction.x != 0 && direction.y != 0 )
		{
			overlapping->emplace_back( direction.x, 0 );
			overlapping->emplace_back( 0, direction.y );
		} else
			overlapping->emplace_back( direction );
	}
}

