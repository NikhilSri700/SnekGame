#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	 
	gfx.DrawRect(loc.x * dimension + cellPadding, loc.y * dimension + cellPadding, dimension - cellPadding * 2, dimension - cellPadding * 2, c);
}

void Board::DrawBoundary()
{
	for (int i = 5; i < 10; i++) // Left 
	{
		for (int j = 3 * dimension + 5; j < gfx.ScreenHeight - 5; j++)
			gfx.PutPixel(i, j, Colors::Blue);
	}
	for (int i = 5; i < gfx.ScreenWidth - 5; i++) // Top
	{
		for (int j = 3 * dimension + 5; j < 4 * dimension - 1; j++)
			gfx.PutPixel(i, j, Colors::Blue);
	}
	for (int i = gfx.ScreenWidth - 10; i < gfx.ScreenWidth - 5; i++) // Right
	{
		for (int j = 3 * dimension + 5; j < gfx.ScreenHeight - 5; j++)
			gfx.PutPixel(i, j, Colors::Blue);
	}
	for (int i = 5; i < gfx.ScreenWidth - 5; i++) // Bottom
	{
		for (int j = gfx.ScreenHeight - 10; j < gfx.ScreenHeight - 5; j++)
			gfx.PutPixel(i, j, Colors::Blue);
	}
}

int Board::getGridWidth()
{
	return width;
}

int Board::getGridHeight()
{
	return height;
}

int Board::getGridDimension()
{
	return dimension;
}
