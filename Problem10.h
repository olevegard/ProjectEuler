#pragma once

#include "Problem.h"
#include "Math.h"

class Problem10 : public Problem
{
	int64_t Solve( )
	{
		return FindSumOfPrimes( 2000000 );
	}
	int64_t FindSumOfPrimes( int32_t max )
	{
		int64_t sum = 2; // First prime

		for ( int32_t i = 3 ; i < max ; i += 2 )
		{
			if ( Math::IsPrime( i ) )
				sum += i;
		}

		return sum;
	}
};
