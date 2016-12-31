#pragma once

/*
	Disabling warning C4458 - "declaration of 'x' hides class member".
*/
#pragma warning(disable:4458)

#include <string>

namespace pi
{
	namespace constants
	{
		namespace pathfinder
		{
			namespace flagNames
			{
				const std::string COLLIDABLE = "COLLIDABLE";
			}
		}

		namespace ui
		{
			constexpr std::uint8_t MAX_CALLBACKS = 8;
			constexpr std::uint8_t MAX_UIELEMENTS = 32;
		}
		
		namespace console
		{
			constexpr std::uint8_t MAX_COMMANDS = 32;
			constexpr std::uint8_t DEAFULT_TEXT_SIZE = 12;
			constexpr std::uint8_t DEAFULT_NUMBER_OF_LINES = 18;
			constexpr std::uint8_t DEAFULT_TEXT_SIZE_IN_LINE = 80;
		}
	}
}