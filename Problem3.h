#pragma once

#include "Math.h"
#include "Problem.h"

class Problem3: public Problem
{
	public:
	Problem3()
	{
		primeNumbers.reserve( 100000 );
	}
	int64_t Solve()
	{
		return FindLargestFactor( 600851475143 );
	}
	void GeneratePrimeNumberList( int64_t max_ )
	{
		int64_t max = sqrt( max_ );
		for ( int64_t num = 1 ; num < max ; ++num )
		{
			if ( Math::IsPrime( num ) )
				primeNumbers.push_back( num );
		}
	}
	int64_t FindLargestFactor( int64_t number )
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
		std::vector< int64_t > primeNumbers;
};
