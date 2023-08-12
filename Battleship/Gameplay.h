#pragma once

#include "Menu.h"
#include "Board.h"
#include "Renderer.h"

using namespace std;

class Gameplay
{
private:
	Board player;
	Board opponent;

	Renderer rend;

public:
	void deploymentManualyPlayer(Board& b);
	void deploymentAutoPlayer(Board& b);

	void deploymentAutoOpponent(Board& b);

	void shootingPlayer(Board& b);

	void startGame();
	void playGame();
};