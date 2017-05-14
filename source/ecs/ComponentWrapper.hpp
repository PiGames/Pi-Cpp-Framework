/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#pragma once

#include <memory>

#include "Config.hpp"

namespace ecs
{
	/*
	===============================================================================
		Wraps component data into structure with useful informations like does its
		parent entity wish delete and owner entity id. Note: data is a shared_ptr,
		so you must use static_cast<ComponentType>(componentWrapper.data) before
		use. 'data' field very often will contain trash from previous users - 
		reset them in your own scope.

	===============================================================================
	*/
	struct componentWrapper_t final
	{
		entityID_t ownerEntityID;
		bool wishDelete;
		const size_t hashCode;
		std::shared_ptr<void> data;

		componentWrapper_t( size_t hash, entityID_t owner = UNASSIGNED_ENTITY_ID ) :
			ownerEntityID( owner ),
			wishDelete( false ),
			hashCode( hash )
		{}
	};
}