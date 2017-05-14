/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#pragma once

#include <ECS/Config.hpp>

namespace ecs
{
	namespace internal
	{
		/*
		===============================================================================
			Extenstion structure for entityID_t. It holds information about working
			order of it (if wishDelete then remove it from System).

		===============================================================================
		*/
		struct entityAttributes_t final
		{
			bool wishDelete;
			entityID_t entityID;

			entityAttributes_t( entityID_t entity = UNASSIGNED_ENTITY_ID ) :
				entityID( entity ),
				wishDelete( false )
			{}
		};
	}
}
