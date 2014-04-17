#pragma once

#include "Problem.h"

#include <vector>
#include <algorithm>
#include <iomanip>

enum class Direction{ Right, Down };
struct Movement
{
	Movement( int x_, int y_ )
	{
		x = x_;
		y = y_;
	}
	int x;
	int y;
	Direction dir;
};
struct Pascal
{
	Pascal()
	{
		level = 0;

		std::vector< int64_t > vec;
		numbers.push_back( vec );
		numbers[0].push_back( 1 );

	}
	void GotoNext()
	{
		std::vector< int64_t > newLevel;
		const std::vector< int64_t > &prevLevel = numbers[level];

		newLevel.push_back( 1 );

		for ( int64_t i = 0 ; ( i + 1 ) < prevLevel.size() ; ++i )
			newLevel.push_back(  prevLevel[i] + prevLevel[i + 1] );

		newLevel.push_back( 1 );
		numbers.push_back( newLevel );

		++level;
	}
	int64_t GetMiddleNumber( int64_t level_ )
	{
		while ( level < level_ )
			GotoNext();

		int64_t middle = numbers[level_].size() / 2;
		return numbers[level_][middle];
	}

	void PrintTriangle() const
	{
		for ( int64_t i = 0; i < numbers.size() ; ++i )
		{
			std::cout << "Level " << std::setw( 4 ) << i << "\t";
			PrintLine( numbers[i] );
		}
	}
	void PrintLine( const std::vector< int64_t > &line ) const
	{
		for ( const auto &num : line )
		{
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}
	int64_t GetLevel() const
	{
		return level;
	}
	private:
		int64_t level;
		std::vector< std::vector< int64_t > > numbers;
};

class Problem15 : public Problem
{
	public:
	Problem15()
		:	columns( 21 ) // 21 points =  20 squares
		,	rows( 21 )
	{
	}
	int64_t Solve()
	{
		Pascal p;
		int64_t level = 40;

		return p.GetMiddleNumber( 20 + 20 );
	}
	// Finds all possible routes
	int64_t SlowSolve()
	{
		FindFirstRoute();
		int64_t count = 1;

		while( FindNextRoute()  )
		{
			++count;
		}
		return count;
	}
	// Finds any route
	bool FindNextRoute()
	{
		//std::cout << "========================= Finding new route =========================\n";
		bool changed = false;
		int i = lastRoute.size() - 1;
		int size = lastRoute.size();

		for ( ; i >= 0 ; --i )
		{
			// Starting at last position of the prev route
			Movement &changeDir = lastRoute[ i ];

			// Can only do something on nodes pointing down
			if ( changeDir.dir != Direction::Down )
				continue;

			// Can only do something if the nodes can be changed to pointing down
			if  ( !CanMove( changeDir.x, changeDir.y, Direction::Right ) )
				continue;

			// Somthing can be done -> new route
			changed = true;

			// changeDir will be set to Direction::Right
			// nextNode will be moved up, right and dir will be Down
			// This needs to be done for every new pat
			// If it can't be done, it meanst there is no more possible routes
			Movement &moveNode = lastRoute[ i + 1 ];
			RotateUp( moveNode, changeDir  );
			
			// So far so good....
			// But this does not work when there you have situations like  ( D -> R -> R -> D ) -> ( R -> D -> D -> R )
			int j = i + 2 ;
			if ( j >= size )
			{
				//std::cout << "\t\tOnly one node next, no further work is needed\n";
				break;
			}

			Movement &isDownNode = lastRoute[ j ];
			if ( isDownNode.dir != Direction::Right || !CanMove( isDownNode.x, isDownNode.y, Direction::Down ) )
			{
				//std::cout << "\t\tThis node ( " << isDownNode.x << ", " << isDownNode.y << " ) already is down or can't move down\n";
				break;
			}

			//std::cout << "\t\tThis node [ " << j << " ] ( " << isDownNode.x << ", " << isDownNode.y << " ) can move up, reconstruction needed\n";
			//std::cout << "\t\tj is " << j << " size is " << lastRoute.size() << std::endl;

			int x = isDownNode.x;
			int y = isDownNode.y - 1;
			--j;

			while ( CanMove(0, y, Direction::Down ) )
			{
				lastRoute[j].x = x;
				lastRoute[j].y = y;
				lastRoute[j].dir = Direction::Down;

				++j;
				++y;
			}
			while ( j < size )
			{
				lastRoute[j].x = x;
				lastRoute[j].y = y;
				lastRoute[j].dir = Direction::Right;

				++j;
				++x;
			}
			break;
		}

		return changed;
	}
	void RotateUp( Movement &move, Movement &changeDir )
	{
		++move.x;
		--move.y;
		move.dir = Direction::Down;

		changeDir.dir = Direction::Right;
	}
	void RotateDown( Movement &move, Movement &changeDir )
	{
		std::cout << "\t\t\tMoving Down-left " << move.x << ", " << move.y << std::endl;
		--move.x;
		++move.y;
		move.dir = Direction::Right;

		if ( CanMove( changeDir.x, changeDir.y, Direction::Down ) )
		{
				changeDir.dir = Direction::Down;
				std::cout << "\t\t\tSetting Dir down " << changeDir.x << ", " << changeDir.y << std::endl;
		}
	}

	void FindFirstRoute( std::vector<Movement> &route )
	{
		auto last = route[ route.size() -1 ];
		int32_t x = last.x;
		int32_t y = last.y;

		if ( last.dir == Direction::Right )
			++x;
		else
			++y;

		while ( !AtGoal( x, y ) )
		{
			Movement move( x, y );
			if ( CanMove( x, y, Direction::Down ) )
			{
				++y;
				move.dir = Direction::Down;
				route.emplace_back( move );
			}
			else if ( CanMove( x, y, Direction::Right) )
			{
				++x;
				move.dir = Direction::Right;
				route.emplace_back( move );
			}
		}

		lastRoute = route;

	}
	void FindFirstRoute()
	{
		int32_t x = 0;
		int32_t y = 0;

		std::vector< Movement > route;

		while ( !AtGoal( x, y ) )
		{
			Movement move( x, y );
			if ( CanMove( x, y, Direction::Down ) )
			{
				++y;
				move.dir = Direction::Down;
				route.push_back( move );
			}
			else if ( CanMove( x, y, Direction::Right) )
			{
				++x;
				move.dir = Direction::Right;
				route.push_back( move );
			}
		}
		lastRoute = route;
	}
	private:
	void PrintRouteOneline()
	{

		//std::cout << "Route : 0 -> 1 -> 2 -> 3 -> 4 ->5 ->6\n";
		std::cout << "\rRoute : ";

		//const auto &r = routes.at( routes.size() - 1);

		for ( const auto &movement : lastRoute )
		{
			if ( movement.dir == Direction::Down )
				std::cout << "D->";
			else
				std::cout << "R->";
		}
		std::cout << std::endl;
	}
	void PrintRoute()
	{

		std::cout << "Route : \n";

		//const auto &r = routes.at( routes.size() - 1);

		for ( const auto &movement : lastRoute )
		{
			std::cout << "\t( " << movement.x << ", " << movement.y << " ";

			if ( movement.dir == Direction::Down )
				std::cout << "D -> \n";
			else
				std::cout << "R -> \n";
		}
	}
	/*
	   void PrintRoute()
	   {
	   std::cout << "Direction : " << std::endl;

	   const auto &r = routes.at( routes.size() - 1);
	   for ( const auto &movement : r )
	   PrintDirection( movement);

	   std::cout << "=================================\n";
	   }
	   */
	bool CanMove( int32_t x, int32_t y, Direction dir )
	{
		if ( dir == Direction::Right && x == ( columns - 1 ) )
			return false;
		if ( dir == Direction::Down && y == (rows - 1 ) )
			return false;

		return true;
	}
	bool AtGoal( int32_t x, int32_t y )
	{
		return ( x == ( columns - 1 ) && y == ( rows - 1 ) );
	}
	void PrintDirection( Direction dir )
	{
		if ( dir == Direction::Down )
			std::cout<< "Down";
		else
			std::cout<< "Right";
	}
	void PrintDirection( Movement move )
	{
		std::cout << "\tPos : " << move.x << ", " << move.y << " Direction : ";
		PrintDirection( move.dir );
		std::cout << std::endl;
	}
	int32_t columns;
	int32_t rows;
	std::vector< Movement > lastRoute;
};
