#pragma once

#include "Math.h"

class Problem3
{
	public:
	Problem3()
	{
		primeNumbers.reserve( 100000 );
	}
	void GeneratePrimeNumberList( uint64_t max_ )
	{
		uint64_t max = sqrt( max_ );
		for ( uint64_t num = 1 ; num < max ; ++num )
		{
			if ( Math::IsPrime( num ) )
				primeNumbers.push_back( num );
		}
	}
	uint64_t FindLargestFactor( uint64_t number )
	{
		GeneratePrimeNumberList( number );

		auto p = std::end( primeNumbers );
		for ( --p; p != std::begin( primeNumbers ) ; --p )
		{
			if ( ( number % (*p) ) == 0 )
				return (*p);
		}

		return 0;
	}

	

	private:
		std::vector< uint64_t > primeNumbers;
};
