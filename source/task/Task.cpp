#include "Task.hpp"

namespace mc
{
	Task::Task( uint8_t _category, uint8_t _kind )
		:category( _category ), kind( _kind ), doing( true )
	{
		generateCommands();
	}
}
