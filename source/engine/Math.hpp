#pragma once

#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

namespace pi
{
	class Math final
	{
	private:
		Math();

	public:
		static double PerlinNoise(double x, double y, double z);
		static void PerlinNoiseInit();
		static float Sign(float x);

	private:
		static double fade(double t);
		static double lerp(double t, double a, double b);
		static double grad(int hash, double x, double y, double z);
	
	};
}
