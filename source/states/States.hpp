#pragma once

#include "engine/Config.hpp"

namespace mc
{
	enum class states_t
	{
		Exit = pi::constants::stateMachine::EXIT_STATE,

		// Temporary
		Menu = 0,
		Play = 1
	};
}