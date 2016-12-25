#include "CollideableObject.h"

CollideableObject::CollideableObject(bool flag):collideable(flag)
{
}

bool CollideableObject::IsCollideable()
{
	return collideable;
}

void CollideableObject::SetCollideableFlag(bool type)
{
	collideable = type;
}
