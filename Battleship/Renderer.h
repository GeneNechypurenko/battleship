#pragma once

#include <windows.h>

enum textcolor
{
	STANDART = 15,
	HIGHLIGHT = 3,
	GREEN = 10,
	RED = 4
};

class Renderer
{
	static HANDLE hSettings;

public:
	void outputAt(short x, short y);
	void outputColor(int textcolor);
	void hideCursor(bool hide);
};