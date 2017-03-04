// Created by: Condzi (but everyone will edit it)
#pragma once

namespace pi
{
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
