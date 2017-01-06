#pragma once

#include <cstdarg>
#include <iostream>
#include <cmath>
#include "engine/Math.hpp"

namespace pi
{
	class WorldHeightmapGenerator
	{
		WorldHeightmapGenerator();
	public:
		static float * Generate(int width, int height, int seed, int accuracy);
	protected:

	private:
		static int actualHeightmapNumber; //= 1;
		static int width;
		static int height;
		static int accuracy;// = 6;

		static void mergeMaps(float* mainTex, float* finalTex, int width, int height);
		static inline float calculateWeight(int i);
		static void bilinearInterpolation(int sourceWidth, int sourceHeight, int destWidth, int destHeight, float* source, float* newImage);
		static void changeContrast(float* source, int width, int height, float power);
	};

}
