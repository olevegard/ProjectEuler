#pragma once

class Math
{
	public:
	static bool IsPrime( uint64_t number )
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
	static int64_t FindPrimeNumber( int64_t numberToFind )
	{
		if ( numberToFind == 1 )
			return 2;

		int64_t primeCount = 1;

		// Start at 2 because 2 is the first prime 
		// By skipping it we can increase by 2 every time
		int64_t i = 3;
		for ( ; primeCount <= numberToFind ; i += 2 )
		{
			if ( IsPrime( i ) )
			{
				++primeCount;
				if ( primeCount == numberToFind )
					return i;
			}
		}
		
		return i; 
	}
	static bool IsDivisible( int64_t number, int64_t divisor )
	{
		return ( ( number % divisor ) == 0 );
	}
	static int64_t Pow( int64_t base, int64_t power )
	{
		int64_t result = base;
		while ( --power )
		{
			result *= base;
		}

		return result;
	}
	static int64_t CharToDigit( char c )
	{
		return c - 48;
	}
	static const char DigitToChar( int32_t digit )
	{
		return digit + 48;
	}

	static int64_t StrToInt( const std::string &str )
	{
		return std::atoll( str.c_str() );
	}

	static uint64_t Factorial( uint64_t number )
	{
		uint64_t product = 1;
		for ( auto i = number ; i > 0 ; --i )
		{
			product *= i;
		}

		return product;
	}
};
struct BigInt
{
	BigInt()
		:	str( "1" )
		,	power( 0 )
	{
		
	}
	BigInt( std::string number )
		:	str( number )
		,	power( 0 )
	{
		
	}
	void Multiply( int32_t number )
	{
		int32_t currentNumber = number;
		std::vector< std::string > results;
		while ( currentNumber > 0 )
		{
			results.push_back (  MultiplyHelper ( currentNumber % 10 ) );
			currentNumber /= 10;
		}

		int32_t lastElement = results.size() - 1;
		for ( int32_t i = lastElement ; i >= 0 ;  --i )
			results[i].insert( results[i].length(), i, '0' );

		while ( results.size() > 1 )
		{
			std::string result = Add( results[0], results[1] );
			results.erase( results.begin() + 1);
			results.erase( results.begin() );
			results.push_back( result );
		}

		//std::cout << "Final result " << str << " x " << number << " = "  << results[0] << std::endl;
		str = results[0];
	}
	std::string Add( std::string number1, std::string number2 )
	{
		if ( number1.length() > number2.length() )
		{
			int32_t diff = number1.length() - number2.length();
			number2.insert(0, diff, '0' );
		}
		else if ( number1.length() < number2.length() )
		{
			int32_t diff = number2.length() - number1.length();
			number1.insert(0, diff, '0' );
		}

		int32_t remainder = 0;
		std::string result = "";
		result.insert( 0, number1.length(), '0' );

		int32_t i = number2.length() - 1;
		for ( ; i >= 0 ; --i  )
		{
			int32_t digit1 = Math::CharToDigit ( number1[i] );
			int32_t digit2 = Math::CharToDigit( number2[i] );

			int32_t sum = digit1 + digit2 + remainder;

			int32_t newValue = ( sum  % 10 );
			remainder = sum / 10;

			result[i] = Math::DigitToChar( newValue );
		}

		if ( remainder != 0 )
			result.insert( 0, 1, Math::DigitToChar( remainder ) );

		return result;
	}
	std::string MultiplyHelper( int32_t digit )
	{
		int32_t remainder = 0;
		std::string answer = "";

		for ( int32_t i = str.length() - 1 ; i >= 0 ; --i  )
		{
			int32_t current = Math::CharToDigit( str[i] );
			int32_t product = ( current * digit ) + remainder;
			int32_t newValue = ( product % 10 );

			remainder = product / 10;
			answer.insert( 0,1, Math::DigitToChar( newValue ) ); 
		}
		if ( remainder != 0 )
			answer.insert( 0,1, Math::DigitToChar( remainder ) ); 

		return answer;
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

