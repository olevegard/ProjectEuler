#pragma once

#include <iostream>
#include "Problem.h"

class Problem14 : public Problem
{
	public:
	Problem14()
		:	enableDebug( false )
	{
	}
	int64_t Solve()
	{
		return FindLargest( 1000000 );
	}
	int64_t FindLargest( int64_t max )
	{
		if ( enableDebug )
			std::cout << "=================== Largest Collatz Size " << max << " ===================\n";

		int64_t currentMax = 0;
		int64_t startingNumberOfMax = 0;

		for ( int64_t i = 3 ; i <max ; ++i )
		{
			int64_t currentSize = FindCollatzSize( i );
			if ( currentSize > currentMax )
			{
				if ( enableDebug )
					std::cout << "New max! Size of : " << i << " is " << currentSize << std::endl;
				currentMax = currentSize;
				startingNumberOfMax  = i;
			}
		}

		if ( enableDebug )
		{
			std::cout << "Largest collatz under " << max
				<< " starts at " << startingNumberOfMax 
				<< " and has " << currentMax << " items\n";
			std::cout << "============================================================\n";
		}

		return currentMax;
	}
	int64_t FindCollatzSize( int64_t collatzStart )
	{
		if ( enableDebug )
			std::cout << "Finding collatz size of " << collatzStart << std::endl;

		int64_t collatzSize = 1;
		int64_t currentCollatz = collatzStart;
		do
		{
			if ( enableDebug )
				std::cout << "\t" << collatzSize << " : ";

			currentCollatz = DoCollatz( currentCollatz );
			++collatzSize;
		}
		while ( currentCollatz != 1 );

		if ( enableDebug )
		{
			std::cout << "Collatz size of " << collatzStart << " is " << collatzSize << std::endl;
			std::cout << "========================================\n";
		}
		return collatzSize;
	}
	int64_t DoCollatz( int64_t num )
	{
		if ( enableDebug )
			std::cout << "Collatz of " << num;

		if ( num % 2 )
			num = ( num * 3 ) + 1;
		else
			num *= 0.5;

		if ( enableDebug )
			std::cout << " is " << num << std::endl;
		return num;
	}
	private:
	bool enableDebug;
};
