#include "Gameplay.h"

void Gameplay::deploymentManualyPlayer(Board& b)
{
	char keyHit;

	bool isVertical = false;

	int x = 0;
	int y = 0;

	int index = 0;

	while (index < SHIPCOUNT)
	{
		b.deploymentPlaceShip(index, x, y, isVertical);

		b.outputPlayerBoard();
		//opponent.outputEnemyBoard();

		keyHit = _getch();

		switch (keyHit)
		{
		case UP:
			player.deploymentMoveUp(index, x, y, isVertical);
			break;

		case DOWN:
			player.deploymentMoveDown(index, x, y, isVertical);
			break;

		case LEFT:
			player.deploymentMoveLeft(index, x, y, isVertical);
			break;

		case RIGHT:
			player.deploymentMoveRight(index, x, y, isVertical);
			break;

		case SPACE:
			player.deploymentRotate(index, x, y, isVertical);
			break;

		case ENTER:
			b.deploymentSetIsOccupied(index, x, y, isVertical);
			b.deploymentFindAvailablePlacement(index, x, y, isVertical);
			index++;
			break;
		}
	}
}

void Gameplay::deploymentAutoPlayer(Board& b)
{
	srand(time(0));
	int index = 0;

	while (index < SHIPCOUNT)
	{
		int x;
		int y;
		bool isVertical;

		b.outputPlayerBoard();
		//opponent.outputEnemyBoard();

		do  {
			x = rand() % BOARDSIZE;
			y = rand() % BOARDSIZE;
			isVertical = rand() % 2;

		} while (!b.deploymentCheckAvailability(index, x, y, isVertical));

		Sleep(500), b.deploymentPlaceShip(index, x, y, isVertical);
		b.deploymentSetIsOccupied(index, x, y, isVertical);

		index++;
	}
}

void Gameplay::deploymentAutoOpponent(Board& b)
{
	srand(time(0));
	int index = 0;

	while (index < SHIPCOUNT)
	{
		int x;
		int y;
		bool isVertical;

		do {
			x = rand() % BOARDSIZE;
			y = rand() % BOARDSIZE;
			isVertical = rand() % 2;

		} while (!b.deploymentCheckAvailability(index, x, y, isVertical));

		b.deploymentPlaceShip(index, x, y, isVertical);
		b.deploymentSetIsOccupied(index, x, y, isVertical);

		index++;
	}
}

void Gameplay::shootingPlayer(Board& b)
{
	char actionKey;

	int x = 0;
	int y = 0;

	while (true)
	{
		b.shootingPlaceSight(x, y);
		b.outputEnemyBoard();

		actionKey = _getch();

		switch (actionKey)
		{
		case UP:
			b.shootingMoveUp(x, y);
			break;

		case DOWN:
			b.shootingMoveDown(x, y);
			break;

		case LEFT:
			b.shootingMoveLeft(x, y);
			break;

		case RIGHT:
			b.shootingMoveRight(x, y);
			break;

		case SPACE:
			b.shootingTakeShot(x, y);
			return;
		}
	}
}

void Gameplay::startGame()
{
	deploymentManualyPlayer(player);
	deploymentAutoPlayer(opponent);

	player.outputPlayerBoard();
	player.outputEnemyBoard();
}

void Gameplay::playGame()
{
	Board* bptr;

	startGame();

	bptr = &opponent;

	while (true)
	{
		shootingPlayer(*(bptr));
	}
}