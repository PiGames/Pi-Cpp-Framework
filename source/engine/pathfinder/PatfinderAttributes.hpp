#pragma once

#include <unordered_map>
#include "engine/ecs/Component.hpp"

namespace pi
{
	// Attributes for pathfinder objects
	class PathfinderAttributes : 
		public Component
	{
	public:
		PathfinderAttributes(GameObject& gameObject);
		
		ComponentType getComponentType();
		
		// Adds flag to flag container
		// name - flag name
		// status - true or false
		void addFlag(const std::string& name, bool status);
		// returns value of flag of given name
		// Be careful! Returns false if doesnt find flag, so use hasFlag if you aren't sure if flag exist
		bool getFlag(const std::string& name);
		// returns true if flag of given name exist
		bool hasFlag(const std::string& name);

		static struct FLAGS
		{
			static const std::string COLLIDABLE;
		};

	private:
		std::unordered_map<std::string, bool> flags;
	};
}
