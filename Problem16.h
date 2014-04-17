#pragma once

#include "Problem.h"

#include <vector>
#include <iostream>

struct BigInt
{
	BigInt()
		:	str( "1" )
		,	power( 0 )
	{
		
	}
	void Double()
	{
		char overflow = '0';
		char overflowPrev = '0';

		for ( int32_t i = str.length() - 1 ; i >= 0 ; --i  )
		{
			switch ( str[i] )
			{
				case '0' :
					str[i] = '0';
					overflow = '0';
					break;
				case '1' :
					str[i] = '2';
					overflow = '0';
					break;
				case '2' :
					str[i] = '4';
					overflow = '0';
					break;
				case '3' :
					str[i] = '6';
					overflow = '0';
					break;
				case '4' :
					str[i] = '8';
					overflow = '0';
					break;
				case '5' :
					str[i] = '0';
					overflow = '1';
					break;
				case '6' :
					str[i] = '2';
					overflow = '1';
					break;
				case '7' :
					str[i] = '4';
					overflow = '1';
					break;
				case '8' :
					str[i] = '6';
					overflow = '1';
					break;
				case '9' :
					str[i] = '8';
					overflow = '1';
					break;
				default :
					str[i] = '0';
					overflow = '0';
					break;
			}

			if ( overflowPrev == '1' )
			{
				if ( str[i] == '9' )
				{
					overflow = '1';
					str[i] = '0';
				}
				else
					++str[i];
			}

			if ( i == 0 && overflow != '0' )
			{
				//std::cout << "Last digit, prepending 1\n";
				str.insert( 0, "1" );
				overflow = '0';
				overflowPrev = '0';
			}
			else if ( overflow != '0' )
			{
				overflowPrev = '1';
				overflow = '0';
			}
			else
				overflowPrev = '0';
		}
		++power;
	}
	int64_t SumOfDigits()
	{
		int64_t sum = 0;

		for ( const auto &ch : str )
		{
			sum += ( ch - '0' );
		}

		return sum;
	}
	std::string str;
	int32_t power;
};
class Problem16 : public Problem
{
	public:
		virtual int64_t Solve()
	{
		std::cout << std::endl;
		BigInt number;

		while ( number.power != 1000 )
			number.Double();

		std::cout << number.power << " : " << number.str << std::endl;

		return number.SumOfDigits();
	}
};
