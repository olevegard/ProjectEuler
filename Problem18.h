#pragma once

#include "Problem.h"
#include "Math.h"

class Problem18 : public Problem
{
	void Init()
	{
		AddLine( { 75 } );
		AddLine( { 95, 64 } );
		AddLine( { 17, 47, 82 } );
		AddLine( { 18, 35, 87, 10 } );
		AddLine( { 20,  4, 82, 47, 65 } );
		AddLine( { 19,  1, 23, 75,  3, 34 } );
		AddLine( { 88,  2, 77, 73,  7, 63, 67 } );
		AddLine( { 99, 65,  4, 28,  6, 16, 70, 92 } );
		AddLine( { 41, 41, 26, 56, 83, 40, 80, 70, 33 } );
		AddLine( { 41, 48, 72, 33, 47, 32, 37, 16, 94, 29 } );
		AddLine( { 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14 } );
		AddLine( { 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57 } );
		AddLine( { 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48 });
		AddLine( { 63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31 } );
		AddLine( {  4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23 } );
	}
	void MergeLines()
	{
		const auto &bottomLine = numbers[ numbers.size() - 1 ];
		auto &topLine = numbers[ numbers.size() - 2 ];

		for ( int32_t i = 0; i < topLine.size(); ++i )
			topLine[i] += std::max ( bottomLine[i], bottomLine[i + 1 ] );

		numbers.erase( numbers.end() - 1 );
	}
	void AddLine( const std::vector< int32_t > &line )
	{
		numbers.push_back ( line );
	}
	int64_t Solve( )
	{
		Init();

		while ( numbers.size() > 1 )
			MergeLines();

		return numbers[0][0];
	}

	private:
	std::vector< std::vector< int32_t > > numbers;
};
