//Created by: Zmienny
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

		//	Generates the heightmap based on seed and accurancy
		static float * generate(int width, int height, int seed, int accuracy);

	private:
		//	Submaps to generate, 6 by default
		static uint8_t subMapsToGenerate;
		//	1 by default
		static uint8_t alreadyGeneratedSubMapsCount;
		//	Heightmap width
		static uint16_t width;
		//	Heightmap height
		static uint16_t height;

		//	Calculate submap weight for the purposes of generating heightmap
		static inline float calculateWeight(uint8_t i);
		//	Merges submaps during generating the final heightmap
		static void mergeMaps(float* mainTex, float* finalTex, int width, int height);
		//	Scales maps to destination size
		static void bilinearInterpolation(int sourceWidth, int sourceHeight, int destWidth, int destHeight, float* source, float* newImage);
		//	Changes map contrast
		static void changeContrast(float* source, int width, int height, float power);
	};

}
