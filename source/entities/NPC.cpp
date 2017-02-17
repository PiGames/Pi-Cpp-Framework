#include "NPC.hpp"

namespace mc
{

	void NPC::setSkills()
	{
		auto compartment = std::pair<int, int>(TaskManager::GetProperty(TaskManager::SKILLS_AMMOUNT_FROM), TaskManager::GetProperty(TaskManager::SKILLS_AMMOUNT_TO));

		auto ammount = std::rand() % (compartment.second - compartment.first) + compartment.first;

		//security tasks
		for (auto&var : TaskManager::GetActionCollection(TaskManager::SECURITY))
			skills.push_back(&var);

		//other tasks...
		for (size_t i = 0; i < ammount - skills.size(); i++)
			skills.push_back(TaskManager::GetRandomTask());
	}

	void NPC::setPriorities()
	{
		//to do
	}

	NPC::NPC(const std::string & name, const sf::Vector2f & pos, float speed)
		:pi::MovableObject(name,pos,speed)
	{
		setSkills();
		setPriorities();
	}
}