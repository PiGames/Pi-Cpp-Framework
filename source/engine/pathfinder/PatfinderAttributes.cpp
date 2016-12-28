#include "PatfinderAttributes.hpp"

namespace pi
{
	struct PathfinderAttributes::FLAGS;
	const std::string PathfinderAttributes::FLAGS::COLLIDABLE;


	PathfinderAttributes::PathfinderAttributes(GameObject & gameObject) : Component(gameObject, this)
	{
	}

	ComponentType pi::PathfinderAttributes::getComponentType()
	{
		return ComponentType::Dry;
	}

	void PathfinderAttributes::addFlag(const std::string & name, bool status)
	{
		flags[name] = status;
	}

	bool PathfinderAttributes::getFlag(const std::string & name)
	{
		auto result = flags.find(name);

		if (result != flags.end())
			return result->second;

		return false;
	}

	bool PathfinderAttributes::hasFlag(const std::string & name)
	{
		auto result = flags.find(name);

		if (result != flags.end())
			return true;

		return false;
	}
}
