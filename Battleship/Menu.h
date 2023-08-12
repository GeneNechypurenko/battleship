#pragma once

#include <iostream>
#include <conio.h>

#include "Renderer.h"

using namespace std;

const char MARKER = 26;

class Menu
{
	Renderer rend;

public:
	bool selectGameMode();
	bool selectDeploymentMethod();
};