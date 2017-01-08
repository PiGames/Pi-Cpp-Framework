#pragma once

#include "States.hpp"
#include "engine/game/State.hpp"

namespace mc
{
	class PlayState final :
		public pi::State
	{
	public:
		PlayState();

		short run();
	};
}