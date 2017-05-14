/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#include <ECS/SystemBase.hpp>

namespace ecs
{
	entityID_t SystemBase::CreateEntity()
	{
		entitiesAttributes.emplace_back();
		entitiesAttributes.back().entityID = this->entitiesAttributes.size();
		return entitiesAttributes.back().entityID = this->entitiesAttributes.size();
	}

	bool SystemBase::DeleteEntity( entityID_t entity )
	{
		if ( entity == UNASSIGNED_ENTITY_ID || !this->IsEntityInSystem( entity ) )
			return false;

		for ( auto& block : this->componentsBlocks )
			for ( auto it = block.data.begin(); it != block.data.end(); it++ )
				if ( it->ownerEntityID == entity )
				{
					it->ownerEntityID = UNASSIGNED_ENTITY_ID;
					it->wishDelete = false;
					break;
				}

		for ( auto it = this->entitiesAttributes.begin(); it != entitiesAttributes.end(); it++ )
			if ( it->entityID == entity )
			{
				this->entitiesAttributes.erase( it );
				return true;
			}

		ECS_ASSERT( false, "Cannot find Entity in entitiesAttributes vector for unknow reason" );
		return false;
	}

	bool SystemBase::SetEntityWishDelete( entityID_t entity, bool val )
	{
		if ( entity == UNASSIGNED_ENTITY_ID || !this->IsEntityInSystem( entity ) )
			return false;

		for ( auto it = this->entitiesAttributes.begin(); it != entitiesAttributes.end(); it++ )
			if ( it->entityID == entity )
			{
				it->wishDelete = val;
				return true;
			}

		ECS_ASSERT( false, "Cannot find Entity in entitiesAttributes vector for unknow reason" );
		return false;
	}

	bool SystemBase::IsEntityInSystem( entityID_t id )
	{
		if ( id == UNASSIGNED_ENTITY_ID )
			return false;

		for ( const auto& attrib : this->entitiesAttributes )
			if ( attrib.entityID == id )
				return true;

		return false;
	}

	std::shared_ptr<std::vector<std::reference_wrapper<componentWrapper_t>>> SystemBase::GetAllEntityComponents( entityID_t entity )
	{
		auto vec = std::make_shared<std::vector<std::reference_wrapper<componentWrapper_t>>>();

		for ( auto& componentBlock : this->componentsBlocks )
			for ( auto& component : componentBlock.data )
				if ( component.ownerEntityID == entity )
				{
					vec->push_back( component );
					// There is only one component of type X per one Entity
					break;
				}

		return vec;
	}

	void SystemBase::ClearAll()
	{
		this->entitiesAttributes.clear();
		this->componentsHashCodes.clear();
		this->componentsBlocks.clear();
	}

	void SystemBase::RemoveAllThatWishToDelete()
	{
		for ( auto it = this->entitiesAttributes.begin(); it != this->entitiesAttributes.end(); )
		{
			if ( it->wishDelete )
				it = this->entitiesAttributes.erase( it );
			else
				it++;
		}

		for ( auto vecIt = this->componentsBlocks.begin(); vecIt != this->componentsBlocks.end(); )
		{
			for ( auto blockIt = vecIt->data.begin(); blockIt != vecIt->data.end(); blockIt++ )
			{
				if ( blockIt->wishDelete )
				{
					blockIt->wishDelete = false;
					blockIt->ownerEntityID = UNASSIGNED_ENTITY_ID;
				}
			}

			if ( vecIt->data.empty() )
				vecIt = this->componentsBlocks.erase( vecIt );
			else
				vecIt++;
		}

	}

	bool SystemBase::isComponentRegistered( size_t componentHashCode )
	{
		return (
			std::find( this->componentsHashCodes.begin(), this->componentsHashCodes.end(), componentHashCode )
			!= this->componentsHashCodes.end()
			);
	}

	void SystemBase::registerComponent( size_t componentHashCode )
	{
		this->componentsHashCodes.push_back( componentHashCode );
	}

	bool SystemBase::isCurrentBlockOverloaded( size_t componentHashCode )
	{
		// We want to allocate new block if there is no any
		if ( !this->componentsBlocks.size() )
			return true;

		for ( auto it = this->componentsBlocks.begin(); it != this->componentsBlocks.end(); it++ )
			if ( it->hashCode == componentHashCode )
			{
				if ( it->HasFreeSpace() )
					return false;
			}

		return true;
	}

	componentWrapper_t SystemBase::addToBlock( entityID_t entity, size_t componentHashCode )
	{
		ecs::componentWrapper_t* freeComponentWrapper = nullptr;
		for ( auto& compblock : this->componentsBlocks )
		{
			// Searching for maching block...
			if ( compblock.hashCode == componentHashCode )
			{
				// Checking if entity already has this component
				for ( const auto& component : compblock.data )
					if ( component.ownerEntityID == entity )
						return componentWrapper_t( 0 );

				if ( compblock.HasFreeSpace() )
					freeComponentWrapper = compblock.GetFreeComponentWrapper();
			}
		}

		ECS_ASSERT( freeComponentWrapper != nullptr, "Couldn't add component to block - no free space" );

		freeComponentWrapper->ownerEntityID = entity;
		return *freeComponentWrapper;
	}

	bool HaveSameComponentTypes( entityID_t first, entityID_t second, SystemBase& system )
	{
		auto firstComponents = system.GetAllEntityComponents( first );
		auto secondComponents = system.GetAllEntityComponents( second );
		std::vector<size_t> firstHashCodes;
		std::vector<size_t> secondHashCodes;

		for ( componentWrapper_t& component : *firstComponents )
			firstHashCodes.push_back( component.hashCode );
		for ( componentWrapper_t& component : *secondComponents )
			secondHashCodes.push_back( component.hashCode );

		for ( auto hash : firstHashCodes )
			if ( std::find( secondHashCodes.begin(), secondHashCodes.end(), hash ) == secondHashCodes.end() )
				return false;

		return true;
	}
}
