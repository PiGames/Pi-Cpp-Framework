/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#pragma once

#include "SystemBase.hpp"

namespace ecs
{
	/*
	===============================================================================
		Wraps entityID_t into System methods like AddComponent. This class is useful
		for predefined Entites with many components. In advanced systems it's called
		"prefab". You must pass System you want to entity add to in constructor.

	===============================================================================
	*/
	class Entity
	{
	public:
		Entity( SystemBase& system, bool setIDonStartUp = true ) :
			idRO( id ),
			owningSystem( system )
		{
			if ( setIDonStartUp )
				this->id = system.CreateEntity();
			else
				this->id = UNASSIGNED_ENTITY_ID;
		}
		virtual ~Entity() = default;

		ecs::Entity& operator=( const ecs::Entity& second )
		{
			// owningSystem is a reference, so this->owningSystem = second.owningSystem doesn't work - cannot reassign a reference.
			*this = Entity( second.owningSystem, false );
			this->id = second.id;
		}

		entityID_t GetID()
		{
			return this->id;
		}
		const entityID_t GetID() const
		{
			return this->id;
		}
		void SetID( entityID_t newID )
		{
			if ( newID != ecs::UNASSIGNED_ENTITY_ID )
				ECS_ASSERT( this->owningSystem.IsEntityInSystem( newID ), "Entity of given ID (" + std::to_string( newID ) + ") is not in system." );
			this->id = newID;
		}

		// Returns shared_ptr of ComponentType; nullptr if found same
		template<class ComponentType>
		std::shared_ptr<ComponentType> AddComponent()
		{
			return std::static_pointer_cast<ComponentType>( this->owningSystem.AddComponent<ComponentType>( this->id ).data );
		}
		// Returns shared_ptr of ComponentType; nullptr if doesn't found
		template<class ComponentType>
		std::shared_ptr<ComponentType> GetComponent()
		{
			return std::static_pointer_cast<ComponentType>( this->owningSystem.GetComponent<ComponentType>( this->id ).data );
		}
		template<class ComponentType>
		bool HasComponent()
		{
			return this->owningSystem.HasComponent<ComponentType>( this->id );
		}

		virtual void SetUpComponents()
		{}
		// Use this method to update custom components, defined only for this Entity or
		// to handle some situations.
		virtual void Update()
		{}

	protected:
		const entityID_t& idRO;
		SystemBase& owningSystem;

	private:
		entityID_t id;
	};

	/*
	====================
	removeUnusedEntities( vector<StorageType>& entities, SystemBase& system, []( StorageType& )->ecs::entityID_t{} )
		Removes entities from vector if Entity ID is not in System. getterLambda should return ID of given entity in StorageType.
	====================
	*/
	template<class StorageType, class GetterLambda>
	inline void removeUnusedEntities( std::vector<StorageType>& entities, SystemBase& system, GetterLambda getterLambda )
	{
		if ( entities.size() == 0 )
			return;

		for ( auto it = entities.begin(); it != entities.end(); )
		{
			if ( !system.IsEntityInSystem( getterLambda( *it ) ) )
				it = entities.erase( it );
			else
				it++;
		}
	}
}