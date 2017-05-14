#pragma once

#include <cinttypes>

#include "piTypes/Coord.hpp"

namespace constants
{
	constexpr int16_t EXIT_STATE = 0;

	namespace worldConstructor
	{
		constexpr auto MAP_PREFIX = "MAP";
	}

	namespace logger
	{
		constexpr auto PREFIX_INFO = "[INFO]";
		constexpr auto PREFIX_SUGGESTION = "[SUGGESTION]";
		constexpr auto PREFIX_WARNING = "[WARNING]";
		constexpr auto PREFIX_ERROR = "[ERROR]";
	}

	namespace cell
	{
		constexpr auto ROTATION_MODES = 4;
		constexpr auto STRAIGHT_ANGLE = 90;
		constexpr pi::constexprCoord_t<int8_t> CELL_DIMENSIONS = { 64,64 };
	}

	namespace error
	{
		namespace singleton
		{
			constexpr auto SINGLETON_NOT_INITED = "Singleon must be inited!";
			constexpr auto SINGLETON_INITED = "Singleon has been inited before";
		}

		namespace mapManager
		{
			constexpr auto NEGATIVE_VALUES = "You need to enter a positive values. Dimensions of map/cell cannot be < 0!";
		}

		namespace worldConstructor
		{
			constexpr auto FAILED_OPEN = "Failed to open file";
		}

		namespace soundObject
		{
			constexpr auto ALREADY_EXIST = "Sound with given name already exists";
			constexpr auto DOES_NOT_EXIST_IN_SYSTEM = "Sound with given doesn't exist in system";
		}
	}
}