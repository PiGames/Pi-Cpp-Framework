//Created by: mvxxx
#pragma once

#include "engine/Config.hpp" 

#include <queue>

class NPC;

namespace mc
{
	//Task
	//Represents a task for AI object
	class Task
	{

	public:
		Task(uint8_t category = 0, uint8_t kind = 0, NPC* npc = nullptr );

		uint8_t GetCategory()
		{
			return category;
		}

		uint8_t GetKind()
		{
			return kind;
		}

		bool operator==( const Task& second )
		{
			return this->kind == second.kind;
		}

		bool inProgress()
		{
			return doing;
		}

	private:

		bool doing;

		const int8_t category;

		const int8_t kind;

		NPC* owner;
	};
}