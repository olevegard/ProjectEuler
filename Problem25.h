#pragma once

#include "Problem.h"
#include "Math.h"

class Problem25 : public Problem
{
	int64_t Solve( )
	{
		std::string number1 = "1";
		std::string number2 = "1";

		int32_t i = 3;

		for ( ;  number1.length() < 1000 ; ++i )
		{
			std::string answer = Math::Add( number1, number2 );
			number2 = number1;
			number1 = answer;
		}
		return i;
	}


};
