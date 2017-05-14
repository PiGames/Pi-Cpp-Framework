/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#pragma once

#include <vector>

#include <ECS/Config.hpp>
#include <ECS/ComponentWrapper.hpp>

namespace ecs
{
	namespace internal
	{
		/*
		===============================================================================
			Component Block data type. It has unique 'hashCode' of types of components
			that are stored. It also has the data vector of componentWrapper_t.

		===============================================================================
		*/
		struct componentBlock_t final
		{
			size_t hashCode;
			std::vector<componentWrapper_t> data;

			componentBlock_t( size_t hash = 0 ) :
				hashCode( hash )
			{}

			template<class ComponentType>
			void ReserveComponents( size_t size )
			{
				for ( size_t i = 0; i < size; i++ )
				{
					this->data.emplace_back( componentWrapper_t( typeid( ComponentType ).hash_code() ) );
					this->data.back().data = std::make_shared<ComponentType>();
				}
			}

			bool HasFreeSpace() const
			{
				for ( auto& componentWrapper : this->data )
					if ( componentWrapper.ownerEntityID == UNASSIGNED_ENTITY_ID )
						return true;

				return false;
			}

			componentWrapper_t* GetFreeComponentWrapper()
			{
				for ( auto& wrapper : this->data )
					if ( wrapper.ownerEntityID == UNASSIGNED_ENTITY_ID )
						return &wrapper;

				return nullptr;
			}
		};
	}
}