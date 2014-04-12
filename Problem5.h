#pragma once

#include <iostream>

class Problem5
{
	public:
	uint64_t FindSmallesMultiple( uint64_t rangeMax )
	{
		for ( auto smallest = rangeMax ; ; smallest += rangeMax )
		{
			if ( IsMultipleOfAll( smallest, rangeMax ) )
				return smallest;
		}
		return 0;
	}
	private:
	bool IsMultipleOfAll( uint64_t number, uint64_t rangeMax )
	{
		for ( auto factor = rangeMax; factor > 0 ; --factor )
		{
			if ( ( number % factor ) != 0 )
				return false;
		}
		return true;
	}
};
