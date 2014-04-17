#pragma once

#include "Problem.h"
#include "Math.h"

class Problem19 : public Problem
{
	public:
	Problem19()
		:	currentDay( 1 )
		,	daysInMonth( { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } )
		,	months( { "January", "February", "March", "April", "May", "June", "July", "August", "September", "october", "November", "December" } )
		,	leapCountDown( 3 )
		,	month( 0 )
		,	year( 1901 )
		,	sundays( 0 )
	{
	}
	void Init()
	{
		days.push_back( "Monday" );
		days.push_back( "Tuesday" );
		days.push_back( "Wedensday" );
		days.push_back( "Thursday" );
		days.push_back( "Friday" );
		days.push_back( "Saturday" );
		days.push_back( "Sunday" );
	}
	void FindNextFirstInMonth()
	{
		std::cout << year << " - " << months[ month ] << " ( " << daysInMonth[ month ] << " ) Day " << currentDay << " is a " << days[ currentDay % 7 ];
		if ( ( currentDay % 7 ) == 6 )
		{
			std::cout << "<------";
			++sundays;
		}

		std::cout << std::endl;

		if ( month == 1 && leapCountDown == 0 )
		{
			std::cout << "Leap year - extra day\n";
			++currentDay;
		}
		currentDay += daysInMonth[month];
		++month;

		if ( month == 12 )
		{
			std::cout << "New year!!!!\n";
			month = 0;
			if ( leapCountDown == 0 )
			{
				leapCountDown = 4;
			}

			--leapCountDown;
			++year;
			//std::cin.ignore();
		}
	}
	int64_t Solve( )
	{
		Init();
		std::cout << std::endl;
		//std::cout << year << " Day " << currentDay << " is a " << days[ currentDay % 7 ] << std::endl;
		while ( year <= 2000 )
			FindNextFirstInMonth();

		return sundays;
	}
	private:
		int32_t currentDay;
		int32_t month;
		int32_t year;
		int32_t leapCountDown;
		int32_t sundays;
		std::vector< std::string > days;
		std::vector< std::string > months;
		std::vector< int32_t > daysInMonth;
};
