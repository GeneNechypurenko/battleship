#pragma once

#include "Menu.h"
#include "Board.h"
#include "Renderer.h"

using namespace std;

class Gameplay
{
private:
	bool gameMode;
	bool deployment;

	Board player;
	Board demo;
	Board opponent;

	Menu menu;

public:
	explicit Gameplay();

	void startGame();
	void playGame();
};