#pragma once

#include <sstream>
class Problem4
{
	public:
	bool IsPalindrome( int32_t number )
	{
		std::stringstream ss;
		ss << number;

		std::string original = ss.str();
		std::string reversed = original;

		std::reverse( std::begin( reversed ), std::end( reversed ) );

		return  ( original == reversed );
	}
	int32_t FindPalindromeProducts()
	{
		int32_t currentMax = 0;
		for ( auto outer = 999 ; outer > 0 ; --outer )
		{
			for ( auto inner = outer - 1 ; inner > 0 ; --inner )
			{
				int32_t product = inner * outer;
				if ( IsPalindrome( product ) && product > currentMax )
				{
					currentMax = product;
				}
			}
		}
		return currentMax;
	}
};
