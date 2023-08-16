#pragma once

#include <conio.h>

#include "Fleet.h"
#include "Renderer.h"
#include "Sight.h"

const int BOARDSIZE = 10;

const char VERTICAL = 186;
const char HORIZONTAL = 205;
const char TOPLEFT = 201;
const char BOTLEFT = 200;
const char TOPRIGHT = 187;
const char BOTRIGHT = 188;

const char WATER = 32;
const char MISS = 15;
const char OCCUPIED = 250;

class Board
{
private:
	char gameBoard[BOARDSIZE][BOARDSIZE];
	bool isOccupied[BOARDSIZE][BOARDSIZE];

	Renderer rend;
	Fleet ship;
	Sight sight;

public:
	explicit Board();

	void outputPlayerBoard();
	void outputEnemyBoard();

	void deploymentSetIsOccupied(int index, int x, int y, bool isVertical);
	bool deploymentCheckAvailability(int index, int x, int y, bool isVertical);
	void deploymentFindAvailablePlacement(int index, int& x, int& y, bool& isVertical);
	void deploymentPlaceShip(int index, int x, int y, bool isVertical);
	void deploymentClearShip(int index, int x, int y, bool isVertical);
	void deploymentMoveUp(int index, int& x, int& y, bool& isVertical);
	void deploymentMoveDown(int index, int& x, int& y, bool& isVertical);
	void deploymentMoveLeft(int index, int& x, int y, bool isVertical);
	void deploymentMoveRight(int index, int& x, int y, bool isVertical);
	void deploymentRotate(int index, int x, int y, bool& isVertical);

	void deploymentManualyRevealBoard(Board& b);
	void deploymentAutoRevealBoard(Board& b);
	void deploymentAutoHiddenBoard(Board& b);

	void shootingSetCellsToMiss(int index, int x, int y);
	char shootingGetShotResult(int x, int y);
	bool shootingCheckHit(int x, int y);
	bool shootingTakeShot(int& x, int& y);
	bool shootingSearchForNextShot(int& x, int& y);

	bool shootingPlayer(Board& b, int& countHits);
	bool shootingOpponentRandomly(Board& b, int& countHits);
	bool shootingOpponentSmart(Board& b, int& countHits);  ///!!!!!!!!!
};