#include "Meter.h"

void Meter::increaseLevel()
{
	level++;
}

void Meter::draw(Graphics & gfx)
{
	int j = 0;
	for (int i = 0; i < level; i++)
	{
		if (i != 0)
		{
			gfx.DrawRect(i * width + space + j, 5, width, height, Color(255, 127, 80));
			j += space;
		}
		else
		{
			gfx.DrawRect(5 + j, 5, width, height, Color(255, 127, 80));
			j += 5;
		}
	}
}

int Meter::getLevel()
{
	return level;
}

