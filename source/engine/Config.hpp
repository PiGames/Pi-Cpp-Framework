#pragma once

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

		namespace physic
		{
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