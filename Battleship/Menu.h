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
	void counterPlayerHits(int countHits, int winCondition);
	void counterOpponetsHits(int countHits, int winCondition);
	void declareWinnerPlayer(int countHits, int winCondition);
	void declareWinnerOpponent(int countHits, int winCondition);
};