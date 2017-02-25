#include "Task.hpp"

namespace mc
{
	Task::Task(uint8_t _category, uint8_t _kind)
		:category(_category), kind(_kind), doing(true)
	{
		generateCommands();
	}

	uint8_t Task::getCategory()
	{
		return category;
	}

	uint8_t Task::getKind()
	{
		return kind;
	}

	bool Task::operator==(const Task & second)
	{
		return this->kind == second.kind;
	}

	bool Task::isDoing()
	{
		return doing;
	}
		
	void Task::generateCommands()
	{
	}

}
