#pragma once

class Problem3
{
	public:
	Problem3()
	{
		primeNumbers.reserve( 100000 );
	}
	void GeneratePrimeNumberList( uint64_t max_ )
	{
		uint64_t max = sqrt( max_ );
		for ( uint64_t num = 1 ; num < max ; ++num )
		{
			if ( IsPrime( num ) )
				primeNumbers.push_back( num );
		}
	}
	uint64_t FindLargestFactor( uint64_t number )
	{
		GeneratePrimeNumberList( number );

		auto p = std::end( primeNumbers );
		for ( --p; p != std::begin( primeNumbers ) ; --p )
		{
			if ( ( number % (*p) ) == 0 )
				return (*p);
		}

		return 0;
	}

	bool IsPrime( uint64_t number )
	{
		// First prime is 2
		if ( number < 2  )
			return false;

		// 2 is a prime number.
		// Need this check because of next if
		if ( number == 2  )
			return true;

		if ( ( number % 2 ) == 0 )
			return false;

		// Only need to check factors between 3 and root of number
		uint64_t root = sqrt( number );

		for ( uint64_t i = 3 ; i <= root ; i += 2 )
		{
			if ( ( number % i ) == 0 )
				return false;
		}

		return true;
	}

	private:
		std::vector< uint64_t > primeNumbers;
};
