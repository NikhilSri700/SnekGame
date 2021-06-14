#pragma once
#include "Graphics.h"
#include "Location.h"
#include<assert.h>

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	void DrawBoundary();
	static int getGridWidth();
	static int getGridHeight();
	static int getGridDimension();
private:
	static constexpr int dimension = 10;
	static constexpr int width = 80;
	static constexpr int cellPadding = 1;
	static constexpr int height = 60;
	Graphics& gfx;
};