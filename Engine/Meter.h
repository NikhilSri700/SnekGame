#pragma once
#include "Graphics.h"

class Meter
{
public:
	void increaseLevel();
	void draw(Graphics& gfx);
	int getLevel();
private:
	static constexpr int height = 20;
	static constexpr int width = 4;
	static constexpr int space = 3;
	int level = 0;
};