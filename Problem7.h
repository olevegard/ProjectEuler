#pragma once

#include "Math.h"
#include "Problem.h"

#include <iostream>

class Problem7: public Problem
{
	public:
	int64_t Solve()
	{
		return static_cast< int64_t > (FindPrimeNumber( 10001 ) );
	}
	int64_t FindPrimeNumber( int64_t numberToFind )
	{
		if ( numberToFind == 1 )
			return 2;

		int64_t primeCount = 1;

		// Start at 2 because 2 is the first prime 
		// By skipping it we can increase by 2 every time
		int64_t i = 3;
		for ( ; primeCount <= numberToFind ; i += 2 )
		{
			if ( Math::IsPrime( i ) )
			{
				++primeCount;
				if ( primeCount == numberToFind )
					return i;
			}
		}
		
		return i; 
	}
};
