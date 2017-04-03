#include "TaskManager.hpp"

namespace mc
{

	std::map<int8_t, std::vector<std::shared_ptr<Task>>> TaskManager::taskData;
	std::map<int8_t, int> TaskManager::npcProperties;

	std::shared_ptr<Task> TaskManager::GetRandomTask()
	{
		auto randomedCategory = std::rand() % (taskData.size() - 2) + 1;
		auto randomedTask = std::rand() % (taskData[randomedCategory].size() - 1);
		return taskData[randomedCategory][randomedTask];
	}

	void TaskManager::loadData()
	{
		{//Security
			taskData.emplace(pi::enumerations::taskManager::taskCategory_t::SECURITY, std::vector<std::shared_ptr<Task>>());

			//taskData[pi::enumerations::taskManager::taskCategory_t::SECURITY].emplace_back(std::make_unique<FirefightingTask>());
		}
	}	
}
