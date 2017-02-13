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

		//Loads data like actions and categories
		//returns false if data hasn't been loaded
		static bool loadData(std::string& actionPath, std::string& categoryPath);

	private:
		static bool loadActions(std::string& path);
		static bool loadCategories(std::string& path);

		/*  CATEGORY, vec<Action>  */
		static std::map<int8_t, std::vector<Task>> taskData;
	};

}
