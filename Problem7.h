#pragma once

#include "Math.h"
#include <iostream>

class Problem7
{
	public:
	uint64_t FindPrimeNumber( uint64_t numberToFind )
	{
		if ( numberToFind == 1 )
			return 2;

		uint64_t primeCount = 1;

		// Start at 2 because 2 is the first prime 
		// By skipping it we can increase by 2 every time
		uint64_t i = 3;
		for ( ; primeCount <= numberToFind ; i += 2 )
		{
			if ( Math::IsPrime( i ) )
			{
				++primeCount;
				if ( primeCount == numberToFind )
					return i;
				//std::cout << i;
				//std::cout << " is prime : " << primeCount << std::endl;
			}
			//else std::cout << " is not prime" << std::endl;
		}
		
		return i; 
	}
};
