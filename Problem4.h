#pragma once

#include <sstream>
#include "Problem.h"

class Problem4: public Problem
{
	public:
	int64_t Solve()
	{
		return FindPalindromeProducts( );
	}
	bool IsPalindrome( int64_t number )
	{
		std::stringstream ss;
		ss << number;

		std::string original = ss.str();
		std::string reversed = original;

		std::reverse( std::begin( reversed ), std::end( reversed ) );

		return  ( original == reversed );
	}
	int64_t FindPalindromeProducts()
	{
		int64_t currentMax = 0;
		for ( auto outer = 999 ; outer > 0 ; --outer )
		{
			for ( auto inner = outer - 1 ; inner > 0 ; --inner )
			{
				int64_t product = inner * outer;
				if ( IsPalindrome( product ) && product > currentMax )
				{
					currentMax = product;
				}
			}
		}
		return currentMax;
	}
};
