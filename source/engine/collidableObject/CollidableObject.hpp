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
		bool IsCollidable();

		//Sets collidable flag
		void SetCollidable(bool flag);

	private:
		bool collidableFlag;
	};
}
