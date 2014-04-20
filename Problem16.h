#pragma once

#include "Problem.h"
#include "Math.h"

#include <vector>
#include <iostream>

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
