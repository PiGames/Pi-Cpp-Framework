// Created by: Condzi
#pragma once

#include <cinttypes>

namespace pi
{
	namespace renderSettings
	{
		struct
		{
			static constexpr uint32_t X = 64;
			static constexpr uint32_t Y = 64;
		} static constexpr MAP_CELL_TEXTURE_SIZE;

		struct
		{
			static constexpr uint32_t X = 32;
			static constexpr uint32_t Y = 32;
		} static constexpr ITEM_TEXTURE_SIZE;

		struct
		{
			static constexpr float X = 100.f;
			static constexpr float Y = 400.f;
		} static constexpr RENDER_OFFSET;

		struct
		{
			static constexpr float X = 1.f;
			static constexpr float Y = 1.f;
		} static constexpr RENDER_SCALE;
	}
}