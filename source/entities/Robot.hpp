// Created by: mvxxx
#pragma once

#include "engine/map/MovableObject.hpp"

namespace mc
{
	//Robot class (main)
	//Represents robot object
	class Robot : public pi::MovableObject
	{
	public:
		Robot( const std::string& name = "<unnamed Robot>", const sf::Vector2f& pos = { 0, 0 }, float speed = 1.f, float batteryCap = 100.f );

	private:
		//Value which represents battery capacity
		const float batteryCapacity;

		//Distance covered
		float distance;

		//The remaining energy
		float energy;
	};
}
