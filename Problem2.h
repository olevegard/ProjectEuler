#pragma once

#include <algorithm>

class Problem2
{
	public:
		Problem2()
			:	prevFib1( 1 )
			,	prevFib2( 0 )
		{
		}
		void AddFibonacciNumbers( int32_t max ) 
		{
			for ( int32_t currentFib = prevFib1 + prevFib2 ; currentFib <= max; currentFib = prevFib1 + prevFib2 )
			{
				prevFib2 = prevFib1;
				prevFib1 = currentFib;

				if ( ( currentFib % 2 ) == 0 )
					evenFibonacciNumbers.push_back( currentFib );
			}
		}
		int32_t CalcFibonacciSum( int32_t max )
		{
			AddFibonacciNumbers( max );
			return std::accumulate( std::begin( evenFibonacciNumbers ), std::end( evenFibonacciNumbers ), 0 );
		}

	private:
		int32_t prevFib1;
		int32_t prevFib2;
		std::vector< int32_t > evenFibonacciNumbers;
};
