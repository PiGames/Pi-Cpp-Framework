#include "TaskManager.hpp"

namespace mc
{

	std::map<int8_t, std::vector<Task>> TaskManager::taskData;
	std::map<int8_t, int> TaskManager::NPC_properties;

	bool TaskManager::LoadData(std::string& actionPath, std::string& categoryPath)
	{
		return (loadCategories(categoryPath) && loadActions(actionPath));
	}

	int TaskManager::GetProperty(pi::enumerations::taskManager::NPC_PROPETIES property)
	{
		return NPC_properties[property];
	}

	std::vector<Task> TaskManager::GetActionCollection(pi::enumerations::taskManager::TASK_CATEGORY category)
	{
		return taskData[category];
	}

	Task * TaskManager::GetRandomTask()
	{
		auto randomedCategory = std::rand() % (taskData.size() - 2) + 1;
		auto randomedTask = std::rand() % (taskData[randomedCategory].size() - 1);
		return &taskData[randomedCategory][randomedTask];
	}


	bool TaskManager::loadCategories(std::string & path)
	{
		std::ifstream file(path);

		if (!file.good())
		{
			pi::Logger::Log(pi::constants::error::fileManager::WRONG_PATH + (std::string)"TaskManager::loadCategories()", pi::Logger::MessageType::Error, pi::Logger::OutputType::Both);
			return false;
		}

		std::string tempCategory;
		
		auto number = 0;

		while (file >> tempCategory)
		{
			taskData.emplace(std::pair<int8_t, std::vector<Task>>(number,std::vector<Task>()));
			number++;
		}

		return true;
	}

	bool TaskManager::loadSkillsAmmount(std::string & path)
	{
		std::ifstream file(path);

		if (!file.good())
		{
			pi::Logger::Log(pi::constants::error::fileManager::WRONG_PATH + (std::string)"TaskManager::loadSkillsAmmount()", pi::Logger::MessageType::Error, pi::Logger::OutputType::Both);
			return false;
		}
		
		auto propertyType = 0;
		int temp;


		while (file >> temp)
		{
			NPC_properties.emplace(propertyType, temp);
			propertyType++;
		}
	}

	bool TaskManager::loadActions(std::string & path)
	{
		std::ifstream file(path);

		if (!file.good())
		{
			pi::Logger::Log(pi::constants::error::fileManager::WRONG_PATH + (std::string)"TaskManager::loadAction()", pi::Logger::MessageType::Error, pi::Logger::OutputType::Both);
			return false;
		}

		std::string tempAction;
		int8_t number;

		while (file >> tempAction)
		{
			file >> number;
			auto itr = taskData.find(number);

			if (itr == taskData.end())
			{
				pi::Logger::Log(pi::constants::error::taskManager::CATEGORY_DOES_NOT_EXIST, pi::Logger::MessageType::Error, pi::Logger::OutputType::Both);
				return false;
			}

			itr->second.emplace_back(Task(number, itr->second.size()));
		}
		return true;
	
	}

}
