#pragma once

#include <iostream>
#include "Problem.h"

class Problem5: public Problem
{
	public:
	int64_t Solve()
	{
		return FindSmallesMultiple( 20 );
	}
	int64_t FindSmallesMultiple( int64_t rangeMax )
	{
		for ( auto smallest = rangeMax ; ; smallest += rangeMax )
		{
			if ( IsMultipleOfAll( smallest, rangeMax ) )
				return smallest;
		}
		return 0;
	}
	private:
	bool IsMultipleOfAll( int64_t number, int64_t rangeMax )
	{
		for ( auto factor = rangeMax; factor > 0 ; --factor )
		{
			if ( ( number % factor ) != 0 )
				return false;
		}
		return true;
	}
};
