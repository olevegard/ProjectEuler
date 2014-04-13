#pragma once

#include "Problem.h"

class Problem6: public Problem
{
	public:
	int64_t Solve()
	{
		return static_cast< int64_t > (GetSumDifference( 100 ) );
	}

	uint64_t GetSumDifference( uint64_t max )
	{
		int64_t sumOfSquares = FindSumOfSquares( max );
		int64_t squareOfSum  = FindSquareOfSum ( max );
		return squareOfSum - sumOfSquares;
	}
	int64_t FindSumOfSquares( uint64_t max )
	{
		int64_t sum = 0;
		for ( int i = 1 ; i <= max ; ++i ) 
		{
			sum += Square( i );
		}
		return sum;
	}
	int64_t FindSquareOfSum( int64_t max )
	{
		int64_t sum = 0;
		for ( int64_t i = 1 ; i <= max ; ++i ) 
		{
			sum += i;
		}
		return Square(sum);
	}
	int64_t Square( int64_t number )
	{
		return number * number;
	}
};
