#pragma once

#include "Problem.h"
#include "Math.h"

class Problem12: public Problem
{
	int64_t Solve( )
	{
		return FindFirstWithDivisorCount( 500 );
	}
	int64_t FindFirstWithDivisorCount( int64_t count )
	{
		int64_t number = 0;
		for ( int64_t i = 1 ; i < 1000000000 ; ++i ) 
		{
			number += i;

			if ( FindDivisorCount( number ) > count )
				return number;
		}

		return 0;
	}
	int64_t FindDivisorCount( int64_t num )
	{
		int64_t divisors = 2;
		int64_t halfNum = sqrt( num );

		for ( int64_t i = 2; i <= halfNum ; ++i )
		{
			if ( ( num % i ) == 0 )
				divisors += 2;
		}
		return divisors;
	}
};
