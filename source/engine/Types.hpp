// Created by: Condzi (but everyone will edit it)
#pragma once

namespace pi
{
	////////////////////
	//	Enumerations  //
	////////////////////

	namespace enumerations
	{
		namespace pathfinder
		{
			enum CellState
			{
				NOT_VISITED = -1,
				START_POSITION = 0
			};

			enum	Direction
			{
				NORTH = 0,
				NORTH_EAST = 1,
				EAST = 2,
				SOUTH_EAST = 3,
				SOUTH = 4,
				SOUTH_WEST = 5,
				WEST = 6,
				NORTH_WEST = 7
			};
		}

		namespace taskManager
		{
			enum TASK_CATEGORY
			{
				SECURITY,
				FOOD
			};

			enum NPC_PROPETIES
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
