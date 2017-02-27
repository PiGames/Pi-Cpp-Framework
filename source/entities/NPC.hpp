//Created by: mvxxx
#pragma once

#include <algorithm>
#include <vector>

#include "engine/map/MovableObject.hpp"

#include "task/Task.hpp"
#include "task/TaskManager.hpp"

namespace mc
{
	//NPC 
	//Represents a single AI object
	class NPC : public pi::MovableObject
	{
	public:

		NPC( const std::string& name = "<unnamed NPC>", const sf::Vector2f& pos = { 0, 0 }, float speed = 1.f );

	private:
		//Skills
		std::vector<Task*> skills;
		//Tasks
		std::vector<Task> tasks;
		std::vector<Task*> priorities;

		void setSkills();
		void setPriorities();
	};
}