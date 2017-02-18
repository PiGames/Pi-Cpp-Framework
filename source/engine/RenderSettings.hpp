// Created by: Condzi
#pragma once

#include <cinttypes>

namespace pi
{
	namespace renderSettings
	{
		struct 
		{
			static constexpr uint32_t x = 64.f;
			static constexpr uint32_t y = 64.f;
		} static constexpr MAP_CELL_TEXTURE_SIZE;

		struct
		{
			static constexpr uint32_t x = 32.f;
			static constexpr uint32_t y = 32.f;
		} static constexpr ITEM_TEXTURE_SIZE;

		struct
		{
			static constexpr float x = 0.f;
			static constexpr float y = 0.f;
		} static constexpr RENDER_OFFSET;

		struct
		{
			static constexpr float x = 5.f;
			static constexpr float y = 5.f;
		} static constexpr RENDER_SCALE;
	}
}