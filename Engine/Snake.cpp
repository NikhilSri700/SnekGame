#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::Consumption(Goal& goal)
{	
	if (goal.getLoc().x == segments[0].getLoc().x &&
		goal.getLoc().y == segments[0].getLoc().y)
	{
		isEaten = true;
	}
}

void Snake::Moveby(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	if (nSegments < nSegmentMax)
	{
		segments[nSegments].InitBody(nSegments);
		nSegments++;
	}
}

void Snake::Draw(Board& brd)
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd, i);
	}
}

bool Snake::IsEaten()
{
	return isEaten;
}

bool Snake::isGameover(Location& in_loc, Board & brd)
{
	if (segments[0].getLoc().x + in_loc.x == 0 ||
		segments[0].getLoc().x + in_loc.x == Board::getGridWidth() - 1 ||
		segments[0].getLoc().y + in_loc.y == 3 ||
		segments[0].getLoc().y + in_loc.y == Board::getGridHeight() - 1)
	{
		return true;
	}
	for (int i = nSegments - 1; i > 0; i--)
	{
		if (segments[0].getLoc().x + in_loc.x == segments[i].getLoc().x &&
			segments[0].getLoc().y + in_loc.y == segments[i].getLoc().y)
		{
			return true;
		}
	}
	return false;
}

void Snake::resetGoal()
{
	isEaten = false;
}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(int index)
{
	if (index % 3 == 0)
	{
		c1 = bodyColor1;
	}
	if (index % 3 == 1)
	{
		c2 = bodyColor2;
	}
	if (index % 3 == 2)
	{
		c3 = bodyColor3;
	}
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) <= 1);
	loc.Add(delta_loc);

}

void Snake::Segment::Draw(Board& brd, int index)
{

	if (index == 0)
	{
		brd.DrawCell(loc, c);
	}
	else
	{
		if (index % 3 == 0)
		{
			brd.DrawCell(loc, c1);
		}
		if (index % 3 == 1)
		{
			brd.DrawCell(loc, c2);
		}
		if (index % 3 == 2)
		{
			brd.DrawCell(loc, c3);
		}
	}
}

Location & Snake::Segment::getLoc()
{
	return loc;
}

