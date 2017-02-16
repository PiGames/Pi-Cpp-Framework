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
		static float Distance(sf::Vector2f first, sf::Vector2f second);

		//Converts real coordinates of point to i|j system
		static sf::Vector2i ConvertPositionToUnitSystem(const sf::Vector2f& data, const sf::Vector2f& cellDimensions);

	private:
		static double fade(double t);
		static double lerp(double t, double a, double b);
		static double grad(int hash, double x, double y, double z);
	};
}
