#pragma once

#include <iostream>

class Problem14
{
	public:
	Problem14()
		:	enableDebug( false )
	{
	}
	uint64_t FindLargest( uint64_t max )
	{
		std::cout << "=================== Largest Collatz Size " << max << " ===================\n";

		uint64_t currentMax = 0;
		uint64_t startingNumberOfMax = 0;

		for ( uint64_t i = 3 ; i <max ; ++i )
		{
			uint64_t currentSize = FindCollatzSize( i );
			if ( currentSize > currentMax )
			{
				if ( enableDebug )
					std::cout << "New max! Size of : " << i << " is " << currentSize << std::endl;
				currentMax = currentSize;
				startingNumberOfMax  = i;
			}
		}

		std::cout << "Largest collatz under " << max
			<< " starts at " << startingNumberOfMax 
			<< " and has " << currentMax << " items\n";
		std::cout << "============================================================\n";

		return currentMax;
	}
	uint64_t DoCollatz( uint64_t num )
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
	uint64_t FindCollatzSize( uint64_t collatzStart )
	{
		if ( enableDebug )
			std::cout << "Finding collatz size of " << collatzStart << std::endl;

		uint64_t collatzSize = 1;
		uint64_t currentCollatz = collatzStart;
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
	private:
	bool enableDebug;
};
