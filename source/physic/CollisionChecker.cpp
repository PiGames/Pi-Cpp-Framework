/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#include "CollisionChecker.hpp"

namespace pi
{
	bool CollisionChecker::AddBoxCollider( std::shared_ptr<BoxCollider> collider )
	{
		if ( !collider )
		{
			Logger::Log( "Cannot add collider to CollisionChecker - collider pointer is not assigned", pi::Logger::MessageType::Error );
		}

		for ( auto ptr : this->colliders )
			if ( ptr.lock() == collider )
			{
				Logger::Log( "Cannot add collider to CollisionChecker - found pointer pointing to same collider", pi::Logger::MessageType::Error );
				return false;
			}

		this->colliders.push_back( collider );

		return true;
	}

	void CollisionChecker::Update( float dt )
	{
		this->removeUnusedEntities();

		for ( size_t i = 0; i < this->colliders.size(); i++ )
			for ( size_t j = 0; j < this->colliders.size(); j++ )
			{
				sf::FloatRect& collA = this->colliders[j].lock()->rectangle;
				sf::FloatRect& collB = this->colliders[i].lock()->rectangle;
				sf::FloatRect collAupdated = collA;
				collAupdated.left += this->colliders[j].lock()->velocity.x * dt;
				collAupdated.top += this->colliders[j].lock()->velocity.y * dt;

				if ( !collAupdated.intersects( collB ) )
					continue;

				this->resolveCollision( this->colliders[j], this->colliders[i], getCollisionSide( collAupdated, collA, collB ) );
			}
	}


	void CollisionChecker::removeUnusedEntities()
	{
		for ( auto it = this->colliders.begin(); it != this->colliders.end();)
		{
			if ( it->expired() )
				it = this->colliders.erase( it );
			else
				it++;
		}
	}

	bool CollisionChecker::collidedLeft( const sf::FloatRect& a, const sf::FloatRect& aOld, const sf::FloatRect& b )
	{
		return aOld.left + aOld.width <= b.left &&
			a.left + a.width >= b.left;
	}

	bool CollisionChecker::collidedRight( const sf::FloatRect& a, const sf::FloatRect& aOld, const sf::FloatRect& b )
	{
		return aOld.left >= b.left + b.width &&
			a.left <= b.left + b.width;
	}

	bool CollisionChecker::collidedDown( const sf::FloatRect& a, /*const sf::FloatRect& aOld,*/ const sf::FloatRect& b )
	{
		// commented for continous checking 
		return //aOld.top + aOld.height <= b.top &&
			a.top + a.height >= b.top;
	}

	bool CollisionChecker::collidedTop( const sf::FloatRect& a, const sf::FloatRect& aOld, const sf::FloatRect& b )
	{
		return aOld.top >= b.top + b.height &&
			a.top <= b.top + b.height;
	}

	collisionSide_t CollisionChecker::getCollisionSide( const sf::FloatRect& collAupdated, const sf::FloatRect& collA, const sf::FloatRect& collB )
	{
		collisionSide_t collAside = collisionSide_t::NONE;

		if ( collidedLeft( collAupdated, collA, collB ) )
			collAside = collisionSide_t::LEFT;
		else if ( collidedRight( collAupdated, collA, collB ) )
			collAside = collisionSide_t::RIGHT;
		else if ( collidedTop( collAupdated, collA, collB ) )
			collAside = collisionSide_t::TOP;
		else if ( collidedDown( collAupdated, /*collA,*/ collB ) )
			collAside = collisionSide_t::DOWN;

		return collAside;
	}

	void CollisionChecker::resolveCollision( std::weak_ptr<BoxCollider> collA, std::weak_ptr<BoxCollider> collB, const collisionSide_t collAside )
	{
		//...
	}
}