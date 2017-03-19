//Created by: mvxxx
#pragma once

#include "Task.hpp"

namespace mc
{
	class FirefightingTask :public Task
	{
	public:

		FirefightingTask( uint8_t category = 0, uint8_t kind = 0, NPC* npc = nullptr );

		virtual bool act() override;
	};
}