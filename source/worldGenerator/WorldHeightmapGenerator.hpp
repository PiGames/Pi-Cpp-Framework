#pragma once

#include <cstdarg>
#include <iostream>
#include <cmath>

#include "engine/Math.hpp"

namespace pi
{
	class WorldHeightmapGenerator
	{

	public:
		WorldHeightmapGenerator() = delete;

		static float * generate(int width, int height, int seed, int accuracy);

	private:
		// Submaps to generate, 6 by default
		static uint8_t subMapsToGenerate;
		// 1 by default
		static uint8_t alreadyGeneratedSubMapsCount;
		static uint16_t width;
		static uint16_t height;

		static inline float calculateWeight(uint8_t i);
		static void mergeMaps(float* mainTex, float* finalTex, int width, int height);
		static void bilinearInterpolation(int sourceWidth, int sourceHeight, int destWidth, int destHeight, float* source, float* newImage);
		static void changeContrast(float* source, int width, int height, float power);
	};

}
