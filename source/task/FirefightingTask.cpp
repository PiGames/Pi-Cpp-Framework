#include "FirefightingTask.hpp"

namespace mc
{
	FirefightingTask::FirefightingTask( uint8_t category, uint8_t kind, NPC* npc )
		:Task( category, kind, npc )
	{
	}

	bool FirefightingTask::act()
	{
		return false;
	}
}
