#pragma once

#include "engine/map/MapObject.hpp"
#include "engine/map/MovableObject.hpp"

namespace mc
{
	class Robot : public pi::MapObject, public pi::MovableObject
	{
	public:
		Robot(const std::string& name = "<unnamed Robot>", const sf::Vector2f& pos = { 0,0 }, const float& speed = 1.f, const float& batteryCap = 100.f);

	private:
		const float batteryCapacity;
		float energy;
	};
}
