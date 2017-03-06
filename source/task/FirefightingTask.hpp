#pragma once

#include "Task.hpp"

namespace mc
{
	class FirefightingTask :public Task
	{
	public:

		FirefightingTask( uint8_t category, uint8_t kind, NPC* npc );

		virtual bool act() override;
	};
}