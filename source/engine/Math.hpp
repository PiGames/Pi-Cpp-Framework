#pragma once

#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <SFML/System/Vector2.hpp>

namespace pi
{
	class Math final
	{
	public:
		Math() = delete;

		static double PerlinNoise(double x, double y, double z);
		static void PerlinNoiseInit();
		static float Sign(float x);
		static float distance(sf::Vector2f first, sf::Vector2f second);

	private:
		static double fade(double t);
		static double lerp(double t, double a, double b);
		static double grad(int hash, double x, double y, double z);	
	};
}
