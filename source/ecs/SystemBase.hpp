/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#pragma once

#include <algorithm>
#include <type_traits>
#include <functional>
#include <iostream>
#include <vector>

#include <ECS/Config.hpp>
#include <ECS/ComponentBlock.hpp>
#include <ECS/EntityAttributes.hpp>
#include <ECS/Assert.hpp>

namespace ecs
{
	/*
	===============================================================================
		Base class for Entity Systems. Use CreateEntity to create it in system and
		get its unique id. Use DeleteEntity to safely remove it from System. To add
		component to entity use AddComponent() method - it returns componentWrapper_t
		structure with your component data.

	===============================================================================
	*/
	class SystemBase
	{
	public:
		SystemBase()
		{
			// Reserving space for components prevents it from moving vector in memory - that caused strange exceptions
			// when I was working on references from ReserveComponentBlocks method - references points to wrong memory
			// when something new was added to componentsBlocks vector.
			this->componentsBlocks.reserve( MAX_COMPONENT_BLOCKS );
		}
		virtual ~SystemBase() = default;

		entityID_t CreateEntity();
		bool DeleteEntity( entityID_t entity );
		bool SetEntityWishDelete( entityID_t entity, bool val );
		bool IsEntityInSystem( entityID_t id );

		// Returns componentWrapper_t with id UNASSIGNED_ENTITY_ID if found same
		template<class ComponentType>
		componentWrapper_t AddComponent( entityID_t entity );
		// Preallocates componetsBlock_t and returns shared_ptr of vector of references to it
		template<class ComponentType>
		std::shared_ptr<std::vector<std::reference_wrapper<internal::componentBlock_t>>> ReserveComponentBlocks( size_t amount );
		// returns componentWrapper_t with id UNASSIGNED_ENTITY_ID if doesn't found
		template<class ComponentType>
		componentWrapper_t GetComponent( entityID_t entity );
		template<class ComponentType>
		bool HasComponent( entityID_t entity );

		// Calls given function with componentWrapper reference and custom parameters for given components
		// Usage: system.ForEach<component_t>(function, additionalArgs, otherAdditionalArgs); 
		template<class ComponentType, typename ...Args>
		void ForEach( std::function<void( SystemBase&, componentWrapper_t&, Args... )>& func, Args&&... args );
		// Calls given function with componentWrapper reference and custom parameters for given components
		// Usage: system.ForEach<component_t>(function, additionalArgs, otherAdditionalArgs); 
		// The only difference between normal ForEach is that here you can call 'raw' funtion instead of packing it in
		// std::function.
		template<class ComponentType, typename Lambda, typename ...Args>
		void ForEachLambda( Lambda func, Args&&... args );

		// Returns shared pointer to vector of std::reference_rapper<componentWrapper_t> with components types
		template<class ComponentType>
		std::shared_ptr<std::vector<std::reference_wrapper<componentWrapper_t>>> GetAllComponentsOfType();
		template<class ComponentType>
		std::shared_ptr<std::vector<entityID_t>> GetAllEntitiesWithComponentOfType();
		// Returns only that components that fulfil following function: std::function<bool(ComponentType&, Args...> 
		template<class ComponentType, typename ...Args>
		std::shared_ptr<std::vector<entityID_t>> GetAllEntitiesWithComponentOfTypeThatFulfilFunction( std::function<bool( ComponentType&, Args... )> func, Args&&... args );
		// Returns only that components that fulfil following lambda: bool (ComponentType&, args...);
		template<class ComponentType, typename Lambda, typename ...Args>
		std::shared_ptr<std::vector<entityID_t>> GetAllEntitiesWithComponentOfTypeThatFulfilLambda( Lambda func, Args&&... args );
		std::shared_ptr<std::vector<std::reference_wrapper<componentWrapper_t>>> GetAllEntityComponents( entityID_t entity );

		void ClearAll();
		// Removes all entities that wished delete and components id marks as UNINITIALIZED.
		void RemoveAllThatWishToDelete();

		// Tests if `first` and `second` have same components.
		friend bool HaveSameComponentTypes( entityID_t first, entityID_t second, SystemBase& system );

	private:
		std::vector<internal::entityAttributes_t> entitiesAttributes;
		std::vector<size_t> componentsHashCodes;
		std::vector<internal::componentBlock_t> componentsBlocks;

		bool isComponentRegistered( size_t componentHashCode );
		void registerComponent( size_t componentHashCode );
		bool isCurrentBlockOverloaded( size_t componentHashCode );
		template<class ComponentType>
		void allocateNewBlock();
		componentWrapper_t addToBlock( entityID_t entity, size_t componentHashCode );
	};

#include "SystemBase.inl"
}