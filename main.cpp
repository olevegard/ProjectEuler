#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"
#include "Problem14.h"

void TestPorblem1();
void TestPorblem2();
void TestPorblem3();
void TestPorblem14();

int main()
{
	TestPorblem1();
	TestPorblem2();
	TestPorblem3();
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
void TestPorblem2()
{
	Problem2 prob2;
	auto answer = prob2.CalcFibonacciSum( 4000000 );
	std::cout << "The answer to problem 2 is : " << answer << std::endl;;
}
void TestPorblem3()
{
	Problem3 prob3;
	auto answer = prob3.FindLargestFactor( 600851475143 );
	std::cout << "The answer to problem 3 is : " << answer << std::endl;;
}
void TestPorblem14()
{
	Problem14 prob;
	auto answer =  prob.FindLargest( 1000000 );
	std::cout << "The answer to problem 14 is : " << answer << std::endl;;
}
