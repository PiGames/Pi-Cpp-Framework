/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#pragma once
#include <cassert>
#include <iostream>
#include <sstream>

#ifdef _MSC_VER
#define __func__ __FUNCTION__
#endif //_MSC_VER

#define ECS_ASSERT( condition, message ) \
do \
{ \
	if(! ( condition ) ) \
	{ \
		std::cerr<<"\nAsseration failed!\n" << \
			"File: " << __FILE__ << \
			"\nFunction: " << __func__ << \
			"\nLine: " << __LINE__ << \
			"\nCondition: " << #condition << \
			"\nMessage: " << message << '\n'; \
		abort();\
	} \
} while ( false )


