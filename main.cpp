#include "Problem1.h"
#include "Problem14.h"

void TestPorblem14();
void TestPorblem1();

int main()
{
	TestPorblem1();
	TestPorblem14();
}
void TestPorblem1()
{
	Problem1 prob1;
	prob1.AddMultiplesBelow( 3, 1000 );
	prob1.AddMultiplesBelow( 5, 1000 );

	auto answer =  prob1.CalcSum();
	std::cout << "The answer to problem 1 is : " << answer << std::endl;;
}
void TestPorblem14()
{
	Problem14 prob;
	auto answer =  prob.FindLargest( 1000000 );
	std::cout << "The answer to problem 14 is : " << answer << std::endl;;
}
