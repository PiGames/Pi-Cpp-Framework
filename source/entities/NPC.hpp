//Created by: mvxxx
#pragma once

#include "engine/map/MovableObject.hpp"
#include "task/Task.hpp"
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
		std::vector<pi::constants::AI::SKILLS> skills;

		//Tasks
		std::vector<Task> tasks;

		std::vector<pi::constants::AI::SKILLS> priorities;
	};
}