//Created by: mvxxx
#pragma once

#include "engine/Config.hpp" 

namespace mc
{
	//Task
	//Represents a task for AI object
	class Task
	{
	public:
		Task(pi::constants::task::CATEGORY category, uint8_t kind);

		uint8_t getCategory();

		uint8_t getKind();

	private:
		const pi::constants::task::CATEGORY category;

		const uint8_t kind;
	};
}