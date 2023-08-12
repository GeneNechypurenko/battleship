#pragma once

#include <windows.h>

enum textcolor
{
	STANDART = 15,
	HIGHLIGHT = 3,
	GREEN = 10,
	RED = 4
};

enum navikeys
{
	ENTER = 13,
	ESC = 27,
	SPACE = 32,
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77
};

class Renderer
{
	static HANDLE hRenderer;

public:
	void outputAt(short x, short y);
	void outputColor(int textcolor);
	void hideCursor(bool hide);
};