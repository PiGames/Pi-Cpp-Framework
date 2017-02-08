#include "Task.hpp"

namespace mc
{
	Task::Task(pi::constants::task::CATEGORY category, uint8_t kind)
		:category(category), kind(kind)
	{
	}

	uint8_t Task::getCategory()
	{
		return category;
	}
	uint8_t Task::getKind()
	{
		return kind;
	}
}
