#pragma once

class Math
{
	public:
	static bool IsPrime( uint64_t number )
	{
		// First prime is 2
		if ( number < 2  )
			return false;

		// 2 is a prime number.
		// Need this check because of next if
		if ( number == 2  )
			return true;

		if ( ( number % 2 ) == 0 )
			return false;

		// Only need to check factors between 3 and root of number
		uint64_t root = sqrt( number );

		for ( uint64_t i = 3 ; i <= root ; i += 2 )
		{
			if ( ( number % i ) == 0 )
				return false;
		}

		return true;
	}
};
