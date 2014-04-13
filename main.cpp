#include "Problem.h"

#include <vector>

#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"
#include "Problem4.h"
#include "Problem5.h"
#include "Problem6.h"
#include "Problem7.h"
#include "Problem8.h"
#include "Problem14.h"

std::vector< Problem* > problems;
Problem1 prob1;
Problem2 prob2;
Problem3 prob3;
Problem4 prob4;
Problem5 prob5;
Problem6 prob6;
Problem7 prob7;
Problem8 prob8;

Problem14 prob14;

void SolveProblem( int32_t problem );
void SolveProblem( Problem* problem );
void SolveAll();

int main()
{
	problems.push_back( &prob1 );
	problems.push_back( &prob2 );
	problems.push_back( &prob3 );
	problems.push_back( &prob4 );
	problems.push_back( &prob5 );
	problems.push_back( &prob6 );
	problems.push_back( &prob7 );
	problems.push_back( &prob8 );
	problems.push_back( &prob14 );

	///SolveProblem( 0 );
	SolveAll();

	SolveProblem( 1 );
}
void SolveProblem( int32_t i )
{
	std::cout << "The answer to problem " << i <<  " is : " << problems[i - 1]->Solve() << std::endl;
}
void SolveAll()
{
	for ( auto i = 0 ; i < problems.size() ; ++i )
		SolveProblem( i + 1  );
}
