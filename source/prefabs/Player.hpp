#pragma once

#include "ecs/Entity.hpp"
#include "components/PlayerController.hpp"
#include "components/Position.hpp"
#include "components/Velocity.hpp"
#include "components/Tag.hpp"
#include "components/Drawable.hpp"

namespace pg
{
	/*
	===============================================================================
	Created by: Condzi
		Player class - represents player. After calling SetUpComponents you MUST
		manually set its Drawable component - sprite and its texture (position is
		automaticly set same as Position Component value).

	===============================================================================
	*/
	class Player final :
		public ecs::Entity
	{
	public:
		Player( ecs::SystemBase& sys ) :
			Entity( sys )
		{}

		void SetUpComponents() override;
		void Update() override;
	};
}