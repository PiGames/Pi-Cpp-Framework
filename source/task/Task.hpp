//Created by: mvxxx
#pragma once

#include "engine/Config.hpp" 

#include <queue>

namespace mc
{
	//Task
	//Represents a task for AI object
	class Task
	{

	public:
		Task( uint8_t category, uint8_t kind );

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

		bool IsDoing()
		{
			return doing;
		}

	private:

		void generateCommands() {}

		union command
		{
			sf::Vector2i target;
			float sleepTime;
		};

		/*type|status*/
		std::queue<std::pair<command, bool>> commandList;


		bool doing;

		const int8_t category;

		const int8_t kind;
	};
}