#pragma once

#include "Board.h"

class Goal
{
public:
	Goal(const Location& in_loc);
	void DrawGoal(Board& brd);
	void ResetLoc(const Location& in_loc);
	Location& getLoc();
private:
	Location loc;
};