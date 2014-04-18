#pragma once

#include "Problem.h"
#include "Math.h"

class Problem20 : public Problem
{
	int64_t Solve( )
	{
		//jfor ( int i = 0 ; i < 25 ; ++ i ) std::cout << "Fac " << Math::Factorial( i ) << std::endl;
		//
		std::cout << std::endl;
		BigInt big( "1" );
		for ( int i = 2 ; i <= 100 ; ++ i )
		{
			big.Multiply( i );
			std::cout << i << "! " << big.str << std::endl;
		}

		std::cout << "Sum of digits " <<  big.SumOfDigits() << std::endl;
		//big.Add( "55555555", "55555555" );

		
		return big.SumOfDigits();
	}

};

