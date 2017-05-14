#include "Physic.hpp"

namespace pg
{
	void Physic::Update( float dt )
	{
		this->updateCurrentEntitiesStorage();
		this->updateVelocity( dt );
		this->updateCollisions( dt );
	}

	void Physic::updateCurrentEntitiesStorage()
	{
		ecs::removeUnusedEntities( this->entities, this->ecsSystem, []( physicEntity_t& ent ) -> ecs::entityID_t
		{
			return ent.id;
		} );
		this->scanForColliderComponent();
		this->scanForVelocityComponent();
	}

	void Physic::updateVelocity( float dt )
	{
		for ( auto& pEntity : this->entities )
		{
			if ( !pEntity.velocity )
				continue;

			auto position = std::static_pointer_cast<PositionComponent>( this->ecsSystem.GetComponent<PositionComponent>( pEntity.id ).data );
			position->x += pEntity.velocity->x * dt;
			position->y += pEntity.velocity->y * dt;
		}
	}

	void Physic::updateCollisions( float dt )
	{
		for ( auto& objectB : this->entities )
		{
			for ( auto& objectA : this->entities )
			{
				if ( objectA.id == objectB.id )
					continue;

				sf::FloatRect rectA = *objectA.collider;
				sf::FloatRect rectB = *objectB.collider;
				sf::FloatRect rectAupdated = rectA;

				if ( objectA.velocity )
				{
					rectAupdated.left += objectA.velocity->x * dt;
					rectAupdated.top += objectA.velocity->y * dt;
				}

				if ( !rectAupdated.intersects( rectB ) )
					continue;

				collidedDirection_t direction = COLLISION_NONE;
				if ( this->collidedTop( rectAupdated, rectA, rectB ) )
					direction = COLLISION_TOP;
				else if ( this->collidedDown( rectAupdated, rectB ) )
					direction = COLLISION_BOTTOM;
				else if ( this->collidedLeft( rectAupdated, rectA, rectB ) )
					direction = COLLISION_LEFT;
				else if ( this->collidedRight( rectAupdated, rectA, rectB ) )
					direction = COLLISION_RIGHT;

				if ( objectA.collider->callback )
					objectA.collider->callback( objectA, objectB, direction, ecsSystem );
				if ( objectB.collider->callback )
					objectB.collider->callback( objectB, objectA,
						[direction]()-> collidedDirection_t
				{
					switch ( direction )
					{
					case COLLISION_TOP: return COLLISION_BOTTOM;
					case COLLISION_BOTTOM: return COLLISION_TOP;
					case COLLISION_LEFT: return COLLISION_RIGHT;
					case COLLISION_RIGHT: return COLLISION_LEFT;
					}
					return COLLISION_NONE;
				}( ), ecsSystem );
			}
		}
	}

	bool Physic::collidedLeft( const sf::FloatRect& a, const sf::FloatRect& aOld, const sf::FloatRect& b )
	{
		return aOld.left + aOld.width <= b.left &&
			a.left + a.width >= b.left;
	}

	bool Physic::collidedRight( const sf::FloatRect& a, const sf::FloatRect& aOld, const sf::FloatRect& b )
	{
		return aOld.left >= b.left + b.width &&
			a.left <= b.left + b.width;
	}

	bool Physic::collidedDown( const sf::FloatRect& a, /*const sf::FloatRect& aOld,*/ const sf::FloatRect& b )
	{
		// commented for continous checking 
		return //aOld.top + aOld.height <= b.top &&
			a.top + a.height >= b.top;
	}

	bool Physic::collidedTop( const sf::FloatRect& a, const sf::FloatRect& aOld, const sf::FloatRect& b )
	{
		return aOld.top >= b.top + b.height &&
			a.top <= b.top + b.height;
	}

	void Physic::scanForColliderComponent()
	{
		for ( ecs::internal::componentBlock_t& block : this->colliderBlocks )
			for ( const auto& component : block.data )
			{
				if ( component.ownerEntityID == ecs::UNASSIGNED_ENTITY_ID )
					continue;
				bool found = false;
				for ( auto& pEntity : this->entities )
				{
					if ( pEntity.id == component.ownerEntityID && !pEntity.collider )
						pEntity.collider = std::static_pointer_cast<ColliderComponent>( component.data );
					else if ( pEntity.id == component.ownerEntityID )
					{
						found = true;
						break;
					}
				}

				if ( !found )
					this->entities.emplace_back( component.ownerEntityID, component.data, nullptr );
			}
	}

	void Physic::scanForVelocityComponent()
	{
		// Doesn't add new entity if only velocity component is found - why should it?
		// Using velocity only it cannot detect collision.
		for ( ecs::internal::componentBlock_t& block : this->velocityBlocks )
			for ( auto& component : block.data )
			{
				if ( component.ownerEntityID == ecs::UNASSIGNED_ENTITY_ID )
					continue;
				for ( auto& pEntity : this->entities )
					if ( pEntity.id == component.ownerEntityID && !pEntity.velocity )
						pEntity.velocity = std::static_pointer_cast<VelocityComponent>( component.data );
			}
	}
}