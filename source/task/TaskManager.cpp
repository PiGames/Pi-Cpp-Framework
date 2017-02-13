#include "TaskManager.hpp"

namespace mc
{

	std::map<int8_t, std::vector<Task>> TaskManager::taskData;

	bool TaskManager::loadData(std::string& actionPath, std::string& categoryPath)
	{
		return (loadCategories(categoryPath) && loadActions(actionPath));
	}

	bool TaskManager::loadCategories(std::string & path)
	{
		std::ifstream file(path);

		if (!file.good())
		{
			pi::Logger::log(pi::constants::error::fileManager::WRONG_PATH + (std::string)"TaskManager::loadCategories()", pi::Logger::MessageType::Error, pi::Logger::OutputType::Both);
			return false;
		}

		std::string tempCategory;
		
		auto number = 0;

		while (file >> tempCategory)
		{
			taskData.emplace(std::pair<int8_t, std::vector<Task>>(number,std::vector<Task>()));
			number++;
		}
	}

	bool TaskManager::loadActions(std::string & path)
	{
		std::ifstream file(path);

		if (!file.good())
		{
			pi::Logger::log(pi::constants::error::fileManager::WRONG_PATH + (std::string)"TaskManager::loadAction()", pi::Logger::MessageType::Error, pi::Logger::OutputType::Both);
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
				pi::Logger::log(pi::constants::error::taskManager::CATEGORY_DOES_NOT_EXIST, pi::Logger::MessageType::Error, pi::Logger::OutputType::Both);
				return false;
			}

			itr->second.emplace_back(Task(number, itr->second.size()));
		}

	}

}
