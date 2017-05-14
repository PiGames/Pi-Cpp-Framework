#include "WorldConstructor.hpp"

namespace pi
{
	void WorldConstructor::CreateWorld( int mapNumber, std::vector<Cell>& map, sf::Vector2i& unitWorldSize ) const
	{
		std::ifstream input( "data/maps/map" + std::to_string( mapNumber ) + ".txt" );

		if ( !input.good() )
		{
			Logger::Log( constants::error::worldConstructor::FAILED_OPEN, Logger::stream_t::BOTH, Logger::type_t::ERROR );
		}

		input >> unitWorldSize.x >> unitWorldSize.y;

		int tempID;

		for ( int j = 0; j < unitWorldSize.y; j++ )
		{
			for ( int i = 0; i < unitWorldSize.x; i++ )
			{
				input >> tempID;
				map.emplace_back( tempID, sf::Vector2i( i, j ) );
			}
		}
	}
}
