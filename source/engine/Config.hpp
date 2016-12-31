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

		namespace componentCache
		{
			constexpr std::uint16_t MAX_COMPONENT_COUNT = 1024;
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


		namespace physic
		{
			namespace boxCollider
			{
				constexpr std::uint8_t MAX_CALLBACKS = 8;
			}

			namespace collisionDetector
			{
				constexpr std::uint16_t MAX_COLLIDERS = 512;
			}

			namespace rigidbody
			{
				constexpr std::uint8_t MAX_COLLIDERS = 8;
			}
		}
	}
}