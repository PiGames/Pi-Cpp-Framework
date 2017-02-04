// Created by: mvxxx
#pragma once

namespace pi
{
	//CollidableObject class
	//It is addon to MapObject (properly StaticObject/MovableObject)
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
