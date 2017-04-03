// Created by: Condzi (but everyone will edit it)
#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "ResourceHolder/ResourceWrapper.hpp"

namespace pi
{
	using textureResource_t = ResourceWrapper<sf::Texture>;
	using fontResource_t = ResourceWrapper<sf::Font>;

	enum class resourcePriorites_t
	{
		UI = 0,
		ENTITIES,
		LEVEL
	};

	enum class textureResourceID_t
	{
		LEVEL_BG = 0,
		ENEMY,
		PLAYER,

		count
	};

	enum class fontResourceID_t
	{
		UI_FONT = static_cast<uint8_t>( textureResourceID_t::count ),

		count
	};

	enum class collisionSide_t
	{
		NONE = -1,
		LEFT = 0,
		RIGHT,
		DOWN,
		TOP
	};

	using cstring_t = const char*;

	////////////////////
	//	Enumerations  //
	////////////////////

	namespace enumerations
	{
		namespace pathfinder
		{
			enum cellState_t
			{
				NOT_VISITED = -1,
				START_POSITION = 0
			};

			enum direction_t
			{
				NORTH,
				NORTH_EAST,
				EAST,
				SOUTH_EAST,
				SOUTH,
				SOUTH_WEST,
				WEST,
				NORTH_WEST
			};
		}

		namespace taskManager
		{
			enum taskCategory_t
			{
				SECURITY,
				FOOD
			};

			enum npcProperties_t
			{
				SKILLS_AMMOUNT_FROM,
				SKILLS_AMMOUNT_TO
			};
		}

		namespace task
		{
			enum status_t
			{
				DONE,
				PROGRESS
			};

		}
	}

	////////////////////
	//	 Structures   //
	////////////////////

	struct MyStruct_t final
	{
		float someVariable;

		void someMethod()
		{
			// Some code - if method is larger than 5 lines then make Types.cpp and there define it
		}
	};
}
