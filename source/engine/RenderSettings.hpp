// Created by: Condzi
#pragma once

#include <cinttypes>

namespace pi
{
	namespace renderSettings
	{
		struct 
		{
			static constexpr uint32_t x = 64;
			static constexpr uint32_t y = 64;
		} static constexpr MAP_CELL_TEXTURE_SIZE;

		struct
		{
			static constexpr uint32_t x = 32;
			static constexpr uint32_t y = 32;
		} static constexpr ITEM_TEXTURE_SIZE;

		struct
		{
			static constexpr float x = 100.f;
			static constexpr float y = 400.f;
		} static constexpr RENDER_OFFSET;

		struct
		{
			static constexpr float x = 1.f;
			static constexpr float y = 1.f;
		} static constexpr RENDER_SCALE;
	}
}