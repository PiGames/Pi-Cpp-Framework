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
	class NPC :public pi::MovableObject
	{
		void setSkills();

		void setPriorities();
	public:

		NPC(const std::string& name = "<unnamed NPC>", const sf::Vector2f& pos = { 0,0 }, float speed = 1.f);

	private:

		//Skills
		std::vector<Task*> skills;

		//Tasks
		std::vector<Task> tasks;

		std::vector<Task*> priorities;
	};
}