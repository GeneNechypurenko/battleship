#include "Board.h"

Board::Board()
{
	for (int i = 0; i < BOARDSIZE; i++)
	{
		for (int j = 0; j < BOARDSIZE; j++)
		{
			gameBoard[i][j] = WATER;
			isOccupied[i][j] = false;
		}
	}
}

void Board::outputPlayerBoard()
{
	short x = 5, y = 2;

	rend.outputColor(GREEN);
	rend.hideCursor(true);

	rend.outputAt(x, y++);
	cout << "   R E S P U B L I C A" << endl;

	rend.outputAt(x, y++);
	cout << "  " << TOPLEFT;

	for (int i = 0; i < BOARDSIZE; i++)
	{
		cout << HORIZONTAL << HORIZONTAL;
	}
	cout << TOPRIGHT << endl;

	for (int i = 0; i < BOARDSIZE; i++)
	{
		rend.outputAt(x, y++);
		cout << i << " " << VERTICAL;

		for (int j = 0; j < BOARDSIZE; j++)
		{
			if (isOccupied[i][j] && gameBoard[i][j] == WATER)
			{
				gameBoard[i][j] = OCCUPIED;
			}
			cout << gameBoard[i][j] << " ";
		}

		cout << VERTICAL << endl;
	}

	rend.outputAt(x, y++);
	cout << "  " << BOTLEFT;
	for (int i = 0; i < BOARDSIZE; i++)
	{
		cout << HORIZONTAL << HORIZONTAL;
	}
	cout << BOTRIGHT << endl;

	rend.outputColor(STANDART);
}

void Board::outputEnemyBoard()
{
	short x = 29, y = 2;

	rend.outputColor(RED);

	rend.outputAt(x, y++);
	cout << "   R E S P U B L I C A" << endl;

	rend.outputAt(x, y++);
	cout << "  " << TOPLEFT;

	for (int i = 0; i < BOARDSIZE; i++)
	{
		cout << HORIZONTAL << HORIZONTAL;
	}
	cout << TOPRIGHT << endl;

	for (int i = 0; i < BOARDSIZE; i++)
	{
		rend.outputAt(x, y++);
		cout << "  " << VERTICAL;

		for (int j = 0; j < BOARDSIZE; j++)
		{
			if (gameBoard[i][j] == HIT || gameBoard[i][j] == MISS || gameBoard[i][j] == SIGHT)
			{
				if (gameBoard[i][j] == SIGHT)
				{
					rend.outputColor(STANDART);
					cout << gameBoard[i][j] << " ";
					rend.outputColor(RED);
				}
				else
				{
					cout << gameBoard[i][j] << " ";
				}
			}
			else
			{
				cout << WATER << " ";
			}
		}

		cout << VERTICAL << " " << i << endl;
	}

	rend.outputAt(x, y++);
	cout << "  " << BOTLEFT;
	for (int i = 0; i < BOARDSIZE; i++)
	{
		cout << HORIZONTAL << HORIZONTAL;
	}
	cout << BOTRIGHT << endl;

	rend.outputColor(STANDART);
}

void Board::deploymentSetIsOccupied(int index, int x, int y, bool isVertical)
{
	if (gameBoard[y][x] == DECK)
	{
		if (isVertical)
		{
			for (int i = 0; i < ship.getSize(index); i++)
			{
				isOccupied[y + i][x] = true;

				if (y + i - 1 >= 0)
				{
					isOccupied[y + i - 1][x] = true;

					if (x - 1 >= 0)
					{
						isOccupied[y + i - 1][x - 1] = true;
					}
					if (x + 1 < BOARDSIZE)
					{
						isOccupied[y + i - 1][x + 1] = true;
					}
				}

				if (y + i + 1 < BOARDSIZE)
				{
					isOccupied[y + i + 1][x] = true;

					if (x - 1 >= 0)
					{
						isOccupied[y + i + 1][x - 1] = true;
					}
					if (x + 1 < BOARDSIZE)
					{
						isOccupied[y + i + 1][x + 1] = true;
					}
				}

				if (x - 1 >= 0)
				{
					isOccupied[y + i][x - 1] = true;
				}
				if (x + 1 < BOARDSIZE)
				{
					isOccupied[y + i][x + 1] = true;
				}
			}
		}
		else
		{
			for (int i = 0; i < ship.getSize(index); i++)
			{
				isOccupied[y][x + i] = true;

				if (y - 1 >= 0)
				{
					isOccupied[y - 1][x + i] = true;

					if (x - 1 >= 0)
					{
						isOccupied[y - 1][x + i - 1] = true;
					}
					if (x + i + 1 < BOARDSIZE)
					{
						isOccupied[y - 1][x + i + 1] = true;
					}
				}

				if (y + 1 < BOARDSIZE)
				{
					isOccupied[y + 1][x + i] = true;

					if (x - 1 >= 0)
					{
						isOccupied[y + 1][x + i - 1] = true;
					}
					if (x + i + 1 < BOARDSIZE)
					{
						isOccupied[y + 1][x + i + 1] = true;
					}
				}

				if (x + i - 1 >= 0)
				{
					isOccupied[y][x + i - 1] = true;
				}
				if (x + i + 1 < BOARDSIZE)
				{
					isOccupied[y][x + i + 1] = true;
				}
			}
		}
	}
}

bool Board::deploymentCheckAvailability(int index, int x, int y, bool isVertical)
{
	if (isVertical)
	{
		if (y + ship.getSize(index) > BOARDSIZE)
		{
			return false;
		}
		for (int i = 0; i < ship.getSize(index); i++)
		{
			if (isOccupied[y + i][x])
			{
				return false;
			}
		}
	}
	else
	{
		if (x + ship.getSize(index) > BOARDSIZE)
		{
			return false;
		}
		for (int i = 0; i < ship.getSize(index); i++)
		{
			if (isOccupied[y][x + i])
			{
				return false;
			}
		}
	}
	return true;
}

void Board::deploymentFindAvailablePlacement(int index, int& x, int& y, bool& isVertical)
{
	for (int i = 0; i < BOARDSIZE; i++)
	{
		for (int j = 0; j < BOARDSIZE; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				if (deploymentCheckAvailability(index, j, i, k))
				{
					x = j;
					y = i;
					isVertical = (k == 1);
					return;
				}
			}
		}
	}
}

void Board::deploymentPlaceShip(int index, int x, int y, bool isVertical)
{
	ship.setShipPosition(index, x, y, isVertical);

	if (isVertical)
	{
		for (int i = 0; i < ship.getSize(index); i++)
		{
			gameBoard[y + i][x] = DECK;
		}
	}
	else
	{
		for (int i = 0; i < ship.getSize(index); i++)
		{
			gameBoard[y][x + i] = DECK;
		}
	}
}

void Board::deploymentClearShip(int index, int x, int y, bool isVertical)
{
	if (isVertical)
	{
		for (int i = 0; i < ship.getSize(index); i++)
		{
			gameBoard[y + i][x] = WATER;
		}
	}
	else
	{
		for (int i = 0; i < ship.getSize(index); i++)
		{
			gameBoard[y][x + i] = WATER;
		}
	}
}

void Board::deploymentMoveUp(int index, int& x, int& y, bool& isVertical)
{
	int tail = ship.getSize(index) - 1;

	deploymentClearShip(index, x, y, isVertical);

	if (y > 0 && deploymentCheckAvailability(index, x, y, isVertical))
	{
		y--;

		if (!deploymentCheckAvailability(index, x, y, isVertical))
		{
			for (int i = y - 1; i >= 0; i--)
			{
				if (!(i < 0) && deploymentCheckAvailability(index, x, i, isVertical))
				{
					y = i;
					break;
				}
				else if (i == 0)
				{
					deploymentFindAvailablePlacement(index, x, y, isVertical);
				}
			}
		}
	}
}

void Board::deploymentMoveDown(int index, int& x, int& y, bool& isVertical)
{
	int tail = ship.getSize(index) - 1;

	deploymentClearShip(index, x, y, isVertical);

	if (y < BOARDSIZE - 1 && isVertical && deploymentCheckAvailability(index, x, y, isVertical)
		|| y < BOARDSIZE - 1 && !isVertical && deploymentCheckAvailability(index, x, y, isVertical))
	{
		y++;

		if (!deploymentCheckAvailability(index, x, y, isVertical))
		{
			for (int i = y + 1; i <= BOARDSIZE; i++)
			{
				if (!(i > BOARDSIZE) && deploymentCheckAvailability(index, x, i, isVertical))
				{
					y = i;
					break;
				}
				else if (i == BOARDSIZE)
				{
					deploymentFindAvailablePlacement(index, x, y, isVertical);
				}
			}
		}
	}
}

void Board::deploymentMoveLeft(int index, int& x, int y, bool isVertical)
{
	int tail = ship.getSize(index) - 1;

	deploymentClearShip(index, x, y, isVertical);

	if (x > 0 && deploymentCheckAvailability(index, x, y, isVertical))
	{
		x--;

		if (!deploymentCheckAvailability(index, x, y, isVertical))
		{
			for (int j = x - 1; j >= 0; j--)
			{
				if (j >= 0 && deploymentCheckAvailability(index, j, y, isVertical))
				{
					x = j;
					break;
				}
				else if (j == 0)
				{
					deploymentFindAvailablePlacement(index, x, y, isVertical);
				}
			}
		}
	}
}

void Board::deploymentMoveRight(int index, int& x, int y, bool isVertical)
{
	int tail = ship.getSize(index) - 1;

	deploymentClearShip(index, x, y, isVertical);

	if (x < BOARDSIZE - 1 && isVertical && deploymentCheckAvailability(index, x, y, isVertical)
		|| x < BOARDSIZE && !isVertical && deploymentCheckAvailability(index, x, y, isVertical))
	{
		x++;

		if (!deploymentCheckAvailability(index, x, y, isVertical))
		{
			for (int j = x + 1; j <= BOARDSIZE; j++)
			{
				if (j <= BOARDSIZE && deploymentCheckAvailability(index, x, j, isVertical))
				{
					x = j;
					break;
				}
				else if (j == BOARDSIZE)
				{
					deploymentFindAvailablePlacement(index, x, y, isVertical);
				}
			}
		}
	}
}

void Board::deploymentRotate(int index, int x, int y, bool& isVertical)
{
	bool canRotate = true;

	if (isVertical)
	{
		if (x + ship.getSize(index) > BOARDSIZE)
		{
			canRotate = false;
		}
		else
		{
			for (int i = 0; i < ship.getSize(index); i++)
			{
				if (isOccupied[y][x + i])
				{
					canRotate = false;
					break;
				}
			}
		}
	}
	else
	{
		if (y + ship.getSize(index) > BOARDSIZE)
		{
			canRotate = false;
		}
		else
		{
			for (int i = 0; i < ship.getSize(index); i++)
			{
				if (isOccupied[y + i][x])
				{
					canRotate = false;
					break;
				}
			}
		}
	}

	if (canRotate)
	{
		if (isVertical)
		{
			for (int i = 0; i < ship.getSize(index); i++)
			{
				gameBoard[y + i][x] = WATER;
			}
			isVertical = false;
		}
		else
		{
			for (int i = 0; i < ship.getSize(index); i++)
			{
				gameBoard[y][x + i] = WATER;
			}
			isVertical = true;
		}
	}
}

void Board::shootingPlaceSight(int x, int y)
{
	gameBoard[y][x] = SIGHT;
}

void Board::shootingClearSight(int x, int y)
{
	if (gameBoard[y][x] == SIGHT)
		gameBoard[y][x] = WATER;
}

char Board::shootingGetShotResult(int x, int y)
{
	return gameBoard[y][x];
}

bool Board::shootingCheckHit(int x, int y)
{
	for (int i = 0; i < SHIPCOUNT; i++)
	{
		if (ship.checkHit(i, x, y))
		{
			gameBoard[y][x] = HIT;
			return true;
		}
	}
	gameBoard[y][x] = MISS;
	return false;
}

void Board::shootingTakeShot(int& x, int& y)
{
	gameBoard[y][x] = WATER;

	if (shootingGetShotResult(x, y) != HIT && shootingGetShotResult(x, y) != MISS)
	{
		shootingCheckHit(x, y);
	}
}

void Board::shootingMoveUp(int& x, int& y)
{
	shootingClearSight(x, y);
	y = (y - 1 + BOARDSIZE) % BOARDSIZE;
}

void Board::shootingMoveDown(int& x, int& y)
{
	shootingClearSight(x, y);
	y = (y + 1) % BOARDSIZE;
}

void Board::shootingMoveLeft(int& x, int& y)
{
	shootingClearSight(x, y);
	x = (x - 1 + BOARDSIZE) % BOARDSIZE;
}

void Board::shootingMoveRight(int& x, int& y)
{
	shootingClearSight(x, y);
	x = (x + 1) % BOARDSIZE;
}


//void Board::printOccupiedCells()
//{
//	rend::setPosXY(42, 2);
//	for (int y = 0; y < BOARDSIZE; y++)
//	{
//		for (int x = 0; x < BOARDSIZE; x++)
//		{
//			if (isOccupied[y][x])
//			{
//				rend::outputAt(rend::posX, rend::posY++);
//				cout << "Occupied cell at (" << y << ", " << x << ")" << endl;
//			}
//		}
//	}
//	rend::setPosXYDefault();
//}