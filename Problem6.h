#pragma once

class Problem6
{
	public:
	uint64_t GetSumDifference( uint64_t max )
	{
		uint64_t sumOfSquares = FindSumOfSquares( max );
		uint64_t squareOfSum  = FindSquareOfSum ( max );
		return squareOfSum - sumOfSquares;
	}
	uint64_t FindSumOfSquares( uint64_t max )
	{
		uint32_t sum = 0;
		for ( int i = 1 ; i <= max ; ++i ) 
		{
			sum += Square( i );
		}
		return sum;
	}
	uint64_t FindSquareOfSum( uint64_t max )
	{
		uint32_t sum = 0;
		for ( int i = 1 ; i <= max ; ++i ) 
		{
			sum += i;
		}
		return Square(sum);
	}
	uint64_t Square( uint64_t number )
	{
		return number * number;
	}
};
