#include "Renderer.h"

HANDLE Renderer::hSettings = GetStdHandle(STD_OUTPUT_HANDLE);

void Renderer::outputAt(short x, short y)
{
	SetConsoleCursorPosition(hSettings, { x,y });
}

void Renderer::outputColor(int textcolor)
{
	SetConsoleTextAttribute(hSettings, textcolor);
}

void Renderer::hideCursor(bool hide)
{

	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hSettings, &structCursorInfo);
	structCursorInfo.bVisible = hide;
	SetConsoleCursorInfo(hSettings, &structCursorInfo);
}