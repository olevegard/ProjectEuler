#pragma once

#include "Problem.h"

#include <vector>
#include <algorithm>
#include <iostream>

class Problem17 : public Problem
{
	public:
	void Init()
	{
		digitNames.push_back( "" ); // Zero is neven said out loud
		digitNames.push_back( "one" );
		digitNames.push_back( "two" );
		digitNames.push_back( "three" );
		digitNames.push_back( "four" );
		digitNames.push_back( "five" );
		digitNames.push_back( "six" );
		digitNames.push_back( "seven" );
		digitNames.push_back( "eight" );
		digitNames.push_back( "nine" );
		digitNames.push_back( "ten" );

		teens.push_back("ten");
		teens.push_back("eleven");
		teens.push_back("twelve");
		teens.push_back("thirteen");
		teens.push_back("fourteen");
		teens.push_back("fifteen");
		teens.push_back("sixteen");
		teens.push_back("seventeen");
		teens.push_back("eighteen");
		teens.push_back("nineteen");

		tensNames.push_back( "" ); // 0 tens (  x > 10 ) is not pronounced ( one, two, three )
		tensNames.push_back( "ten" ); // 1 tens (  9 < x < 20 ) is  pronounced in a different way ( eleven, twelve, thirteeh, fourteen )
		tensNames.push_back( "twenty" );
		tensNames.push_back( "thirty" );
		tensNames.push_back( "forty" );
		tensNames.push_back( "fifty" );
		tensNames.push_back( "sixty" );
		tensNames.push_back( "seventy" );
		tensNames.push_back( "eighty" );
		tensNames.push_back( "ninety" );

		hundred = "hundred"; 
	}
	int64_t GetLetterCount( int64_t number )
	{
		int32_t digits =      ( number % 10    );
		int32_t tens =      ( ( number % 100   ) / 10 );
		int32_t hundreds =  ( ( number % 1000  ) / 100 );
		int32_t thousands = ( ( number % 10000 ) / 1000 );

		std::stringstream ss;

		if ( number >= 1000 && thousands != 0  )
			ss << digitNames[thousands] << " " << "thousand ";

		if ( number >= 100 && hundreds != 0)
		{
			if ( tens == 0 && digits == -0 )
				ss << digitNames[hundreds] << " " << hundred << " ";
			else
				ss << digitNames[hundreds] << " " << hundred << " and ";
		}

		if ( tens != 1 )
			ss << tensNames[tens] << " " << digitNames[digits];
		else
			ss << teens[digits];

		std::string str = ss.str();

		auto pos = std::remove_if( std::begin( str ), std::end( str ), []( char ch ){ return ( ( ch == ' ' ) || ( ch == '-'  ) ); } );
		str.erase( pos, std::end( str  ) );

		return str.length();
	}
	int64_t Solve()
	{
		Init();
		int64_t count = 0;

		for ( int i = 1 ; i <= 1000 ; ++i )
			count += GetLetterCount( i  );

		return count;
	}

	std::vector< std::string > digitNames;
	std::vector< std::string > teens;
	std::vector< std::string > tensNames;
	std::string hundred;
};

