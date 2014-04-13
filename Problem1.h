#pragma once

#include "Problem.h"

#include <vector>
#include <iostream>

class Problem1 : public Problem
{
	public:
	virtual long Solve()
	{
		AddMultiplesBelow( 3, 1000 );
		AddMultiplesBelow( 5, 1000 );
		return CalcSum();
	}
	void AddMultiplesBelow( int64_t start, int64_t stop )
	{
		for ( int64_t num = start ; num < stop ; num  += start )
		{
			if ( CheckIfNumberExists( num ) )
				continue;

			multiples.push_back( num );
		}
	}
	int64_t CalcSum()
	{
		int64_t sum = 0;
		for ( const auto &num : multiples )
			sum += num;

		return sum;
	}
	private:
	bool CheckIfNumberExists( int64_t number )
	{
		for ( const auto &addedNumber : multiples )
		{
			if ( addedNumber == number )
				return true;
		}

		return false;
	}

	std::vector< int64_t > multiples;
};
