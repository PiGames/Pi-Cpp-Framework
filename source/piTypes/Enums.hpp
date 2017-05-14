#pragma once

namespace pg
{
	enum class entityID_t
	{
		UNDEFINED = 0,
		PLAYER,
		ENEMY,

		PLATFORM,

		GUI_BUTTON_PLAY,
		GUI_BUTTON_EXIT
	};

	enum renderLayer_t
	{
		LAYER_MAP = 0,
		LAYER_PLAYER,
		LAYER_UI
	};
}