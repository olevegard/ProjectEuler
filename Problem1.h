#pragma once

#include <vector>
#include <iostream>

class Problem1
{
	public:
	void AddMultiplesBelow( int32_t start, int32_t stop )
	{
		for ( int32_t num = start ; num < stop ; num  += start )
		{
			if ( CheckIfNumberExists( num ) )
				continue;

			multiples.push_back( num );
		}
	}
	int32_t CalcSum()
	{
		int32_t sum = 0;
		for ( const auto &num : multiples )
			sum += num;

		return sum;
	}
	private:
	bool CheckIfNumberExists( int32_t number )
	{
		for ( const auto &addedNumber : multiples )
		{
			if ( addedNumber == number )
				return true;
		}

		return false;
	}

	std::vector< int32_t > multiples;
};
