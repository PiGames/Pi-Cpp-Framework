//Created by: mvxxx
#pragma once

#include "engine/Config.hpp"
#include "task/Task.hpp"
#include "entities/NPC.hpp"

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
		static enum TASK_CATEGORY
		{
			SECURITY,
			FOOD
		};

		static enum NPC_PROPETIES
		{
			SKILLS_AMMOUNT_FROM,
			SKILLS_AMMOUNT_TO
		};

		//Loads data like actions and categories
		//returns false if data hasn't been loaded
		static bool LoadData(std::string& actionPath, std::string& categoryPath);

		static int GetProperty(NPC_PROPETIES property);

		static std::vector<Task> GetActionCollection(TASK_CATEGORY category);

		static Task* GetRandomTask();

	private:
		static bool loadActions(std::string& path);
		static bool loadCategories(std::string& path);
		static bool loadSkillsAmmount(std::string& path);

		/*  TASK_CATEGORY, vec<Action>  */
		static std::map<int8_t, std::vector<Task>> taskData;

		/*  NPC_PROPETIES, vec<data>  */
		static std::map<int8_t, int> NPC_properties;
	};

}
