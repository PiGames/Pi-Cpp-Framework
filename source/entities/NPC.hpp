//Created by: mvxxx
#pragma once

#include "engine/map/MovableObject.hpp"
#include "task/Task.hpp"
#include "task/TaskManager.hpp"
#include <vector>

namespace mc
{
	//NPC 
	//Represents a single AI object
	class NPC
	{
	public:

		NPC();

	private:

		//Skills
		std::vector<Task*> skills;

		//Tasks
		std::vector<Task> tasks;

		std::vector<Task*> priorities;
	};
}