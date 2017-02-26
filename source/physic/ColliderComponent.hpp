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

	struct CollisionInfo final
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

		CollisionInfo( ColliderComponent* p, pi::Entity* e, CollisionInfo::side_t s ) { collider = p; entity = e; side = s; }
	};

	class ColliderComponent
	{
		friend class CollisionHandler;

	public:
		ColliderComponent( pi::Entity* ent, Velocity* v ) :collisionRect( 0, 0, 0, 0 ), entity( ent ), velocity( v ), name( "<unnamed collider>" ) {}

		sf::FloatRect& GetCollisionRect() { return this->collisionRect; }
		std::string GetColliderName() { return this->name; }

		void SetColliderName( const std::string& n ) { this->name = n; }
		void SetCollisionRect( const sf::FloatRect& rect ) { this->collisionRect = rect; };
		void SetCallback( std::function<void( CollisionInfo )> f ) { this->callback = f; }

	protected:
		sf::FloatRect collisionRect;
		std::function<void( CollisionInfo )> callback;

		Velocity* velocity;
		pi::Entity* entity;
		std::string name;
	};
}