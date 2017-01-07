#pragma once

#include "engine/map/MovableObject.hpp"

namespace mc
{
	class Robot : public pi::MovableObject
	{
	public:
		Robot(const std::string& name = "<unnamed Robot>", const sf::Vector2f& pos = { 0,0 }, const float& speed = 1.f, const float& batteryCap = 100.f);

	private:
		//Value which represents battery capacity
		const float batteryCapacity;

		//Distance covered
		float distance;

		//The remaining energy
		float energy;
	};
}
