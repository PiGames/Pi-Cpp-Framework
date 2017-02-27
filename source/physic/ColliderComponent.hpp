#pragma once

#include <functional>

#include <SFML/Graphics/Rect.hpp>

#include "VelocityComponent.hpp"

namespace pi
{
	class Entity;
}

namespace mc
{
	class ColliderComponent;

	struct collisionInfo_t final
	{
		ColliderComponent* collider = nullptr;
		pi::Entity* entity = nullptr;
		enum side_t
		{
			None = -1,
			Left = 0,
			Right,
			Top,
			Down
		} side = None;

		collisionInfo_t( ColliderComponent* p, pi::Entity* e, collisionInfo_t::side_t s )
		{
			collider = p; entity = e; side = s;
		}
	};

	class ColliderComponent
	{
		friend class CollisionHandler;

	public:
		ColliderComponent( pi::Entity* ent, Velocity* v ) :collisionRect( 0, 0, 0, 0 ), entity( ent ), velocity( v ), name( "<unnamed collider>" ) {}

		sf::FloatRect& GetCollisionRect()
		{
			return this->collisionRect;
		}
		std::string GetColliderName()
		{
			return this->name;
		}

		void SetColliderName( const std::string& name )
		{
			this->name = name;
		}
		void SetCollisionRect( const sf::FloatRect& rect )
		{
			this->collisionRect = rect;
		}
		void SetCallback( std::function<void( collisionInfo_t )> function )
		{
			this->callback = function;
		}

	protected:
		sf::FloatRect collisionRect;
		std::function<void( collisionInfo_t )> callback;

		Velocity* velocity;
		pi::Entity* entity;
		std::string name;
	};
}