#pragma once

namespace pi
{
	template<class T>
	struct constexprCoord_t
	{
		T x, y;
		constexpr constexprCoord_t( T xx, T yy ) :
			x( xx ), y( yy )
		{}
	};
}