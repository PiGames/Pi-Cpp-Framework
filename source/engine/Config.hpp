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
				constexpr auto COLLIDABLE = "COLLIDABLE";
			}
		}

		namespace ui
		{
			constexpr std::uint8_t MAX_CALLBACKS = 8;
			constexpr std::uint8_t MAX_UIELEMENTS = 32;
			constexpr std::uint8_t NUMBER_OF_UI_ELEMENTS = 4;
		}
		
		namespace console
		{
			constexpr std::uint8_t MAX_COMMANDS = 32;
			constexpr std::uint8_t DEAFULT_TEXT_SIZE = 12;
			constexpr std::uint8_t DEAFULT_NUMBER_OF_LINES = 18;
			constexpr std::uint8_t DEAFULT_TEXT_SIZE_IN_LINE = 80;
		}

		namespace worldConstructor
		{
			constexpr auto CELL = "Cell";
			constexpr auto TEXTURE_FILE_PATH = "data/textures/textureAtlas.png";
			constexpr auto ID_FILE_PATH = "id.txt";
		}

		namespace soundSystem
		{
			constexpr auto SOUND_PATH = "data/sound/";
			constexpr auto SOUND_FORMAT = ".ogg";
		}

		namespace stateMachine
		{
			constexpr std::int8_t EXIT_STATE = -1;
		}

		namespace error
		{
			namespace soundSystem
			{
				constexpr auto ALREADY_EXIST = "Sound with given name exist now";
				constexpr auto DOES_NOT_EXIST_IN_FOLDER = "Sound with given name isn't in source folder";
				constexpr auto DOES_NOT_EXIST_IN_SYSTEM = "Sound with given name doesn't exist in system. Firstly you need add it to system. Use emplaceSound (std::string name)";
			}
		}
	}
}