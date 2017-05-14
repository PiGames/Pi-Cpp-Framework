#pragma once

#include "Config.hpp"

namespace pg
{
	// Game state enumerations
	enum state_t : uint8_t
	{
		// Change to config value later.
		STATE_EXIT = constants::EXIT_STATE,
		STATE_INIT,
		STATE_MENU,
		STATE_PLAY,

		SUB_STATE_MENU_MAIN,
		SUB_STATE_MENU_OPTIONS,
		SUB_STATE_MENU_CREDITS,

		SUB_STATE_PLAY_MAIN,
		SUB_STATE_PLAY_GAMEOVER,
		SUB_STATE_PLAY_PAUSE
	};
}