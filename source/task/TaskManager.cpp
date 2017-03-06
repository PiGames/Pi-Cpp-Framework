#include "TaskManager.hpp"

namespace mc
{

	std::map<int8_t, std::vector<Task>> TaskManager::taskData;
	std::map<int8_t, int> TaskManager::npcProperties;

	Task * TaskManager::GetRandomTask()
	{
		auto randomedCategory = std::rand() % (taskData.size() - 2) + 1;
		auto randomedTask = std::rand() % (taskData[randomedCategory].size() - 1);
		return &taskData[randomedCategory][randomedTask];
	}

}
