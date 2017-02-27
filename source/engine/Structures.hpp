#pragma once

namespace pi
{
	struct constexpr_string_t
	{
		const char * str;
		const size_t size;

		template<size_t count>
		constexpr constexpr_string_t( const char( &str )[count] ) :
			str( str ),
			size( count - 1 ) // do not count'\0'
		{
		}
	};
}