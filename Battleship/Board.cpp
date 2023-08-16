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
	short x = 35, y = 8;

	rend.outputColor(GREEN);

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
	short x = 60, y = 8;

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
			if (gameBoard[i][j] == HIT || gameBoard[i][j] == MISS)
			{
				cout << gameBoard[i][j] << " ";
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
		|| y + tail < BOARDSIZE - 1 && !isVertical && deploymentCheckAvailability(index, x, y, isVertical))
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

void Board::deploymentMoveLeft(int index, int& x, int y, bool isVertical)  //??!!
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
				if (!(j > 0) && deploymentCheckAvailability(index, j, y, isVertical))
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

void Board::deploymentMoveRight(int index, int& x, int y, bool isVertical)  //??!!
{
	int tail = ship.getSize(index) - 1;

	deploymentClearShip(index, x, y, isVertical);

	if (x < BOARDSIZE - 1 && isVertical && deploymentCheckAvailability(index, x, y, isVertical)
		|| x + tail < BOARDSIZE && !isVertical && deploymentCheckAvailability(index, x, y, isVertical))
	{
		x++;

		if (!deploymentCheckAvailability(index, x, y, isVertical))
		{
			for (int j = x + 1; j <= BOARDSIZE; j++)
			{
				if (!(j > BOARDSIZE) && deploymentCheckAvailability(index, j, x, isVertical))
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

void Board::deploymentManualyRevealBoard(Board& b)
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

		keyHit = _getch();

		switch (keyHit)
		{
		case UP:
			b.deploymentMoveUp(index, x, y, isVertical);
			break;

		case DOWN:
			b.deploymentMoveDown(index, x, y, isVertical);
			break;

		case LEFT:
			b.deploymentMoveLeft(index, x, y, isVertical);
			break;

		case RIGHT:
			b.deploymentMoveRight(index, x, y, isVertical);
			break;

		case SPACE:
			b.deploymentRotate(index, x, y, isVertical);
			break;

		case ENTER:
			b.deploymentSetIsOccupied(index, x, y, isVertical);
			b.deploymentFindAvailablePlacement(index, x, y, isVertical);
			index++;
			break;
		}
	}
}

void Board::deploymentAutoRevealBoard(Board& b)
{
	srand(time(0));

	int index = 0;

	while (index < SHIPCOUNT)
	{
		int x;
		int y;
		bool isVertical;

		b.outputPlayerBoard();

		do {
			x = rand() % BOARDSIZE;
			y = rand() % BOARDSIZE;
			isVertical = rand() % 2;

		} while (!b.deploymentCheckAvailability(index, x, y, isVertical));

		Sleep(500), b.deploymentPlaceShip(index, x, y, isVertical);
		b.deploymentSetIsOccupied(index, x, y, isVertical);

		index++;
	}
}

void Board::deploymentAutoHiddenBoard(Board& b)
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

void Board::shootingSetCellsToMiss(int index, int x, int y)  //??!!
{
	int head;
	int tail = ship.getSize(index);

	if (ship.getIsVertical(index))
	{
		head = ship.getShipY(index);

		if (x > 0)
		{
			gameBoard[head - 1][x - 1] = MISS;
		}
		if (head > 0)
		{
			gameBoard[head - 1][x] = MISS;
		}
		if (x < BOARDSIZE - 1)
		{
			gameBoard[head - 1][x + 1] = MISS;
		}

		if (head + tail < BOARDSIZE - 1 && x > 0)
		{
			gameBoard[head + tail][x - 1] = MISS;
		}
		if (head + tail < BOARDSIZE - 1)
		{
			gameBoard[head + tail][x] = MISS;
		}
		if (head + tail < BOARDSIZE - 1 && x < BOARDSIZE - 1)
		{
			gameBoard[head + tail][x + 1] = MISS;
		}

		for (int i = 0; i < ship.getSize(index); i++)
		{
			if (x > 0)
			{
				gameBoard[head + i][x - 1] = MISS;
			}
			if (x < BOARDSIZE - 1)
			{
				gameBoard[head + i][x + 1] = MISS;
			}
		}
	}
	else
	{
		head = ship.getShipX(index);

		if (head > 0 && y > 0)
		{
			gameBoard[y - 1][head - 1] = MISS;
			gameBoard[y + 1][head - 1] = MISS;
			gameBoard[y][head - 1] = MISS;
		}

		if (y > 0)
		{
			gameBoard[y - 1][head + tail] = MISS;
		}
		if (head + tail < BOARDSIZE - 1)
		{
			gameBoard[y][head + tail] = MISS;
		}
		if (y < BOARDSIZE - 1)
		{
			gameBoard[y + 1][head + tail] = MISS;
		}

		for (int i = 0; i < ship.getSize(index); i++)
		{
			if (y > 0)
			{
				gameBoard[y - 1][head + i] = MISS;
			}
			if (y < BOARDSIZE - 1)
			{
				gameBoard[y + 1][head + i] = MISS;
			}
		}
	}

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

			if (ship.getIsDestroyed(i))
			{
				shootingSetCellsToMiss(i, x, y);
			}

			return true;
		}
	}
	gameBoard[y][x] = MISS;
	return false;
}

bool Board::shootingTakeShot(int& x, int& y)
{
	if (gameBoard[y][x] == HIT || gameBoard[y][x] == MISS)
	{
		return false;
	}

	gameBoard[y][x] = WATER;

	if (shootingGetShotResult(x, y) != HIT && shootingGetShotResult(x, y) != MISS)
	{
		shootingCheckHit(x, y);
		return true;
	}
}

bool Board::shootingSearchForNextShot(int& x, int& y)
{
	for (int j = 0; j < BOARDSIZE; j++)
	{
		for (int i = 0; i < BOARDSIZE; i++)
		{
			if (gameBoard[j][i] == HIT)
			{
				for (int k = 0; k < SHIPCOUNT; k++)
				{
					if (ship.searchForHit(k))
					{
						x = i, y = j;
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Board::shootingPlayer(Board& b, int& countHits)
{
	bool isHit = false;
	bool endTurn = false;
	int x, y;

	char actionKey;

	while (!endTurn)
	{
		b.outputEnemyBoard();

		sight.outputSight();

		actionKey = _getch();

		switch (actionKey)
		{
		case UP:
			sight.moveUp();
			break;

		case DOWN:
			sight.moveDown();
			break;

		case LEFT:
			sight.moveLeft();
			break;

		case RIGHT:
			sight.moveRight();
			break;

		case SPACE:
			x = sight.convertToGameBoardX();
			y = sight.convertToGameBoardY();

			if (!b.shootingTakeShot(x, y))
			{
				endTurn = false;
			}
			else
			{
				if (b.shootingGetShotResult(x, y) == HIT)
				{
					isHit = true;
					countHits++;
				}
				endTurn = true;
			}
			break;
		}
	}
	return isHit;
}

bool Board::shootingOpponentRandomly(Board& b, int& countHits)
{
	bool isHit = false;
	bool endTurn = false;
	int x, y;

	while (!endTurn)
	{
		x = rand() % 10;
		y = rand() % 10;

		if (b.shootingGetShotResult(x, y) != HIT && b.shootingGetShotResult(x, y) != MISS)
		{
			if (b.shootingCheckHit(x, y))
			{
				isHit = true;
				countHits++;
			}
			endTurn = true;
		}
	}
	return isHit;
}

bool Board::shootingOpponentSmart(Board& b, int& countHits) //!!!!!!!!!!!!!!!!!!
{
	bool isHit = false;
	bool endTurn = false;
	int x, y;

	while (!endTurn)
	{
		if (b.shootingSearchForNextShot(x, y))
		{
			if (y > 0 && y < BOARDSIZE - 1 && b.shootingGetShotResult(x, y - 1) != HIT && b.shootingGetShotResult(x, y - 1) != MISS)
			{
				y--;
			}
			else if	(y > 0 && y < BOARDSIZE - 1 && b.shootingGetShotResult(x, y + 1) != HIT && b.shootingGetShotResult(x, y + 1) != MISS)
			{
				y++;
			}	
			else if (x > 0 && x < BOARDSIZE - 1 && b.shootingGetShotResult(x, y - 1) == HIT || b.shootingGetShotResult(x, y - 1) == MISS)
			{
				x--;
			}
			else if (y > 0 && y < BOARDSIZE - 1 && b.shootingGetShotResult(x, y + 1) == HIT || b.shootingGetShotResult(x, y + 1) == MISS)
			{
				x++;
			}

			if (b.shootingCheckHit(x, y))
			{
				isHit = true;
				countHits++;
			}
			endTurn = true;
		}

		else
		{
			x = rand() % 10;
			y = rand() % 10;

			if (b.shootingGetShotResult(x, y) != HIT && b.shootingGetShotResult(x, y) != MISS)
			{
				if (b.shootingCheckHit(x, y))
				{
					isHit = true;
					countHits++;
				}
				endTurn = true;
			}
		}
	}
	return isHit;
}