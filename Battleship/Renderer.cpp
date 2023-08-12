#include "Renderer.h"

HANDLE Renderer::hRenderer = GetStdHandle(STD_OUTPUT_HANDLE);

void Renderer::outputAt(short x, short y)
{
	SetConsoleCursorPosition(hRenderer, { x,y });
}

void Renderer::outputColor(int textcolor)
{
	SetConsoleTextAttribute(hRenderer, textcolor);
}

void Renderer::hideCursor(bool hide)
{

	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hRenderer, &structCursorInfo);
	structCursorInfo.bVisible = hide;
	SetConsoleCursorInfo(hRenderer, &structCursorInfo);
}