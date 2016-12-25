#pragma once

class CollideableObject
{
	bool collideable;
public:
	CollideableObject(bool flag);
	bool IsCollideable();
	void SetCollideableFlag(bool type);
};