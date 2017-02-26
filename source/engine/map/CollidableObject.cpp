#include "CollidableObject.hpp"

namespace pi
{
	CollidableObject::CollidableObject( bool flag ) :collidableFlag( flag )
	{
	}

	bool CollidableObject::IsCollidable()
	{
		return collidableFlag;
	}

	void CollidableObject::SetCollidable( bool flag )
	{
		collidableFlag = flag;
	}
}
