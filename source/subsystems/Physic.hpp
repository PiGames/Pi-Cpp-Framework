#pragma once

#include <functional>
#include <cmath>

#include "components/Collider.hpp"
#include "components/Velocity.hpp"
#include "components/Position.hpp"
#include "ecs/ComponentBlock.hpp"
#include "ecs/SystemBase.hpp"
#include "ecs/Entity.hpp"

namespace pg
{
	enum collidedDirection_t
	{
		COLLISION_NONE = 0,
		COLLISION_TOP,
		COLLISION_BOTTOM,
		COLLISION_LEFT,
		COLLISION_RIGHT
	};

	// Helper structure for Physics entities.
	struct physicEntity_t final
	{
		ecs::entityID_t id;
		std::shared_ptr<ColliderComponent> collider;
		std::shared_ptr<VelocityComponent> velocity;

		physicEntity_t( ecs::entityID_t entityID, std::shared_ptr<void> coll, std::shared_ptr<void> vel ) :
			id( entityID ),
			collider( std::static_pointer_cast<ColliderComponent>( coll ) ),
			velocity( std::static_pointer_cast<VelocityComponent>( vel ) )
		{}
	};

	/*
	===============================================================================
	Created by: Uriel
		Physic is class where you can set velocity and collider coponenty blocks to checked
		and updated for collision event.

	===============================================================================
	*/
	class Physic final
	{
	public:
		Physic( ecs::SystemBase& base ) :
			ecsSystem( base )
		{}

		void SetColliderComponentBlocks( std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>>& components )
		{
			this->colliderBlocks = components;
		}
		void SetVelocityComponentBlocks( std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>>& components )
		{
			this->velocityBlocks = components;
		}

		// Clear collider and velocity vector
		void ClearData()
		{
			this->collider.clear();
			this->velocityBlocks.clear();
		}

		void Update( float dt );

	private:
		ecs::SystemBase& ecsSystem;
		std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>> collider;
		std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>> colliderBlocks;
		std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>> velocityBlocks;
		std::vector<physicEntity_t> entities;

		std::vector<std::pair<std::shared_ptr<VelocityComponent>, std::shared_ptr<ColliderComponent>>> getColliders();

		void updateCurrentEntitiesStorage();
		void updateVelocity( float dt );
		void updateCollisions( float dt );

		bool collidedLeft( const sf::FloatRect& a, const sf::FloatRect& aOld, const sf::FloatRect& b );
		bool collidedRight( const sf::FloatRect& a, const sf::FloatRect& aOld, const sf::FloatRect& b );
		bool collidedDown( const sf::FloatRect& a, /*const sf::FloatRect& aOld,*/ const sf::FloatRect& b );
		bool collidedTop( const sf::FloatRect& a, const sf::FloatRect& aOld, const sf::FloatRect& b );

		void scanForColliderComponent();
		void scanForVelocityComponent();
	};
}