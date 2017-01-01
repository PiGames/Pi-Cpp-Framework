#include "CollidableObject.hpp"

namespace pi
{
	CollidableObject::CollidableObject(bool flag) :collidableFlag(flag)
	{
	}

	bool CollidableObject::isCollidable()
	{
		return collidableFlag;
	}

	void CollidableObject::setCollidable(bool flag)
	{
		collidableFlag = flag;
	}
}
