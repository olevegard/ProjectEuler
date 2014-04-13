#pragma once

#include "Problem.h"
#include <algorithm>

class Problem2: public Problem
{
	public:
		Problem2()
			:	prevFib1( 1 )
			,	prevFib2( 0 )
		{
		}

		int64_t Solve()
		{
			return CalcFibonacciSum( 4000000 );
		}
		void AddFibonacciNumbers( int64_t max ) 
		{
			for ( int64_t currentFib = prevFib1 + prevFib2 ; currentFib <= max; currentFib = prevFib1 + prevFib2 )
			{
				prevFib2 = prevFib1;
				prevFib1 = currentFib;

				if ( ( currentFib % 2 ) == 0 )
					evenFibonacciNumbers.push_back( currentFib );
			}
		}
		int64_t CalcFibonacciSum( int64_t max )
		{
			AddFibonacciNumbers( max );
			return std::accumulate( std::begin( evenFibonacciNumbers ), std::end( evenFibonacciNumbers ), 0 );
		}

	private:
		int64_t prevFib1;
		int64_t prevFib2;
		std::vector< int64_t > evenFibonacciNumbers;
};
