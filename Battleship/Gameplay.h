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

	int countHitsPlayer;
	int countHitsOpponent;
	const int winCondition;

	Board player;
	Board demo;
	Board opponent;

	Menu menu;

	Renderer rend;

public:
	explicit Gameplay();

	void startGame();
	void playGame();
};