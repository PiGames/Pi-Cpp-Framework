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
		Task(uint8_t category, uint8_t kind);

		uint8_t getCategory();

		uint8_t getKind();

		bool operator==(const Task& second);

	private:
		const int8_t category;

		const int8_t kind;
	};
}