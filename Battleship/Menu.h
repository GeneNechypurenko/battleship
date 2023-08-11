#pragma once

#include <iostream>
#include <conio.h>

#include "Renderer.h"

using namespace std;

const char MARKER = 26;

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

class Menu
{
	Renderer rend;

public:
	bool selectDeploymentMethod();
};