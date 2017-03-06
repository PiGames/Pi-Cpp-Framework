//Created by: mvxxx
#pragma once

#include "engine/Config.hpp"
#include "engine/Types.hpp"

#include "entities/NPC.hpp"
#include "task/Task.hpp"
#include "task/FirefightingTask.hpp"

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

		static void loadData();

	private:

		/*  TASK_CATEGORY, vec<Action_ID>  */
		static std::map<int8_t, std::vector<Task>> taskData;

		/*  NPC_PROPETIES, vec<property>  */
		static std::map<int8_t, int> npcProperties;
	};

}
