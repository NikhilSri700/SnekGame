#pragma once

#include "Board.h"
#include "Goal.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& in_loc);
		void InitBody(int index);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd, int index);
		Location& getLoc();
	private:
		Location loc;
		Color c;
		Color c1;
		Color c2;
		Color c3;
	};
public:
	Snake(const Location& loc);
	void Consumption(Goal& goal);
	void Moveby(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd);
	bool IsEaten();
	bool isGameover(Location& in_loc, Board& brd);
	void resetGoal();
private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor1 = Colors::Green;
	static constexpr Color bodyColor2 = Color(50,205,50);
	static constexpr Color bodyColor3 = Color(34, 139, 34);
	static constexpr int nSegmentMax = 1000;
	Segment segments[nSegmentMax];
	int nSegments = 1;
	bool isEaten = false;
};
