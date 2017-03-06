//Created by: mvxxx
#pragma once

#include "engine/Config.hpp"
#include "task/Task.hpp"
#include "entities/NPC.hpp"
#include "engine/Types.hpp"

#include <fstream>
#include <vector>
#include <map>


namespace mc
{
	//TaskManager
	//Simple class to control bots
	class TaskManager final
	{
	public:

		static int GetProperty( pi::enumerations::taskManager::npcProperties_t property )
		{
			return npcProperties[property];
		}

		static std::vector<Task>& GetActionCollection( pi::enumerations::taskManager::taskCategory_t category )
		{
			return taskData[category];
		}

		static Task* GetRandomTask();

	private:

		/*  TASK_CATEGORY, vec<Action>  */
		static std::map<int8_t, std::vector<Task>> taskData;

		/*  NPC_PROPETIES, vec<data>  */
		static std::map<int8_t, int> npcProperties;
	};

}
