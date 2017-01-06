#pragma once

namespace pi
{
	class CollidableObject
	{
	public:
		//Constructor 
		//flag <=> collidable flag (default false)
		CollidableObject(bool flag = false);

		//Returns flag
		bool isCollidable();

		//Sets collidable flag
		void setCollidable(bool flag);

	private:
		bool collidableFlag;
	};
}
