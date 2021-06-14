#include "Goal.h"

Goal::Goal(const Location & in_loc)
	:
	loc(in_loc)
{
}

void Goal::DrawGoal(Board & brd)
{
	brd.DrawCell(loc, Color(255, 127, 80));
}


void Goal::ResetLoc(const Location & in_loc)
{
	loc = in_loc;
}

Location & Goal::getLoc()
{
	return loc;
}
