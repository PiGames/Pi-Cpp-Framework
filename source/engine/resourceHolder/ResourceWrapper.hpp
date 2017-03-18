#pragma once

#include <cinttypes>

namespace pi
{
	/*
	===============================================================================
	Created by: Condzi
		Wrapper class for common resources. Usage: ResourceWrapper<sf::Texture> textureResoure;
		It has two fields - priority and resourceID. 
		Priority is how valuable is resource - for example if we are loading level
		we want to remove all resources except UI.
		resourceID is ID of resource - it can be PLAYER_TEXTURE, MAP_TEXTURE_SHEET etc.

	===============================================================================
	*/
	template<class Resource>
	class ResourceWrapper final :
		public Resource
	{
	public:
		ResourceWrapper() :
			priority( 0 ), resourceID( 0 )
		{}
		ResourceWrapper( const Resource& res ) :
			Resource( res ),
			priority( 0 ), resourceID( 0 )
		{}

		uint8_t GetResourcePriority()
		{
			return this->priority;
		}
		uint8_t GetResourceID()
		{
			return this->resourceID;
		}

		void SetResourcePriority( uint8_t val )
		{
			this->priority = val;
		}
		void SetResourceID( uint8_t val )
		{
			this->resourceID = val;
		}

	private:
		uint8_t priority, resourceID;
	};
}