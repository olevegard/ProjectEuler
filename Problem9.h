#pragma once

#include "Problem.h"
#include <iostream>

class Problem9 : public Problem
{
	public:
		bool IsPythagoran( int32_t a, int32_t b, int32_t c )
		{
			if ( !( ( a < b ) && ( b < c ) ) )
				return false;

			int32_t aa = a * a;
			int32_t bb = b * b;
			int32_t cc = c * c;

			int32_t ab = aa + bb;

			if ( ab == cc )
				return true;
			else
				return false;
		}
		bool IsSum1000( int32_t a, int32_t b, int32_t c )
		{
			int32_t sum = a + b + c;
			return ( sum == 1000 );
		}
		int64_t FindProduct()
		{
			for ( int32_t c = 1000 ; c > 0 ; --c )
			{
				int32_t cc = c * c;
				for ( int32_t b = 500 ; b > 0 ; --b )
				{
					// c2 = b2 + a2 
					// a2 = c2 - b2
					if ( ( c -b ) > b )
						continue;

					int32_t bb = b * b;
					int32_t aa = cc - bb;
					int32_t a = sqrt( aa );

					if ( !IsSum1000( a, b, c) )
						continue;

					if ( !IsPythagoran( a, b, c ) )
						continue;

					return a * b * c;
				}
			}

			return 0;
		}
		int64_t Solve( )
		{
			return FindProduct();
		}
};
