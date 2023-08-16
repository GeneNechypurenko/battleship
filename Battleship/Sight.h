#pragma once

#include <iostream>
#include <windows.h>

#include "Renderer.h"

using namespace std;

const int YMIN = 10;
const int YMAX = 19;

const int XMIN = 63;
const int XMAX = 81;

class Sight
{
	const char sight;
	short x;
	short y;

	static HANDLE hSight;

public:
	explicit Sight();

	void outputSight() const;
	void clearSight() const;
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void setDefault();
	int convertToGameBoardX();
	int convertToGameBoardY();
};