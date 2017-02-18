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
		for (auto&var : skills)
			if (var->getCategory() == TaskManager::TASK_CATEGORY::SECURITY)
				priorities.push_back(var);
			else break;

			std::vector<Task*> temporaryTaskCollection;

			for (size_t i = priorities.size(); i < skills.size(); i++)
				temporaryTaskCollection.push_back(skills[i]);

			while(!temporaryTaskCollection.empty())
			{
				auto index = std::rand() % temporaryTaskCollection.size();

				priorities.push_back(temporaryTaskCollection[index]);

				temporaryTaskCollection.erase(std::find(temporaryTaskCollection.begin(), temporaryTaskCollection.end(), temporaryTaskCollection[index]));
			}
	}

	NPC::NPC(const std::string & name, const sf::Vector2f & pos, float speed)
		:pi::MovableObject(name,pos,speed)
	{
		setSkills();
		setPriorities();
	}
}