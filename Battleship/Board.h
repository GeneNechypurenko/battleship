#pragma once

#include "Fleet.h"
#include "Renderer.h"

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

const char SIGHT = 43;

class Board
{
private:
	char gameBoard[BOARDSIZE][BOARDSIZE];
	bool isOccupied[BOARDSIZE][BOARDSIZE];

	Renderer rend;
	Fleet ship;

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

	void shootingPlaceSight(int x, int y);
	void shootingClearSight(int x, int y);
	char shootingGetShotResult(int x, int y);
	bool shootingCheckHit(int x, int y);
	void shootingTakeShot(int& x, int& y);
	void shootingMoveUp(int& x, int& y);
	void shootingMoveDown(int& x, int& y);
	void shootingMoveLeft(int& x, int& y);
	void shootingMoveRight(int& x, int& y);







	void printB();
	void printOccupiedCells();
};