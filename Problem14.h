#pragma once

#include <iostream>

class Problem14
{
	public:
	Problem14()
		:	enableDebug( false )
	{
	}
	uint32_t FindLargest( uint32_t max )
	{
		std::cout << "=================== Largest Collatz Size " << max << " ===================\n";

		uint32_t currentMax = 0;
		uint32_t startingNumberOfMax = 0;

		for ( int i = 3 ; i <max ; ++i )
		{
			uint32_t currentSize = FindCollatzSize( i );
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
	uint32_t DoCollatz( uint32_t num )
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
	int32_t FindCollatzSize( uint32_t collatzStart )
	{
		if ( enableDebug )
			std::cout << "Finding collatz size of " << collatzStart << std::endl;

		uint32_t collatzSize = 1;
		uint32_t currentCollatz = collatzStart;
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
