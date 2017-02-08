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
	struct CollisionInfo final
	{
		ColliderComponent* collider = nullptr;
		pi::Entity* entity = nullptr;
		enum Side
		{
			None = -1,
			Left = 0,
			Right,
			Top,
			Down
		} side = None;

		CollisionInfo(ColliderComponent* p, pi::Entity* e, CollisionInfo::Side s) { collider = p; entity = e; side = s; }
	};

	class ColliderComponent
	{
		friend class CollisionHandler;

	public:
		ColliderComponent(pi::Entity* ent, Velocity* v) :collisionRect(0, 0, 0, 0), entity(ent), velocity(v), name("<unnamed collider>") { }

		sf::FloatRect& getCollisionRect() { return this->collisionRect; }
		std::string getColliderName() { return this->name; }

		void setColliderName(const std::string& n) { this->name = n; }
		void setCollisionRect(const sf::FloatRect& rect) { this->collisionRect = rect; };
		void setCallback(std::function<void(CollisionInfo)> f) { this->callback = f; }

	protected:
		sf::FloatRect collisionRect;
		std::function<void(CollisionInfo)> callback;

		Velocity* velocity;
		pi::Entity* entity;
		std::string name;
	};
}