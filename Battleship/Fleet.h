#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char DECK = 254;
const char HIT = 'X';

const int SHIPCOUNT = 10;

const int DECKS[SHIPCOUNT] =
{
	4,
	3, 3,
	2, 2, 2,
	1, 1, 1, 1
};

class Fleet
{
private:

	struct Ship
	{
		int size;
		int shipX;
		int shipY;
		bool isVertical;
		bool isDestroyed;
		vector <char> depiction;

		Ship(int size);
	};

	vector<Ship> ships;

public:
	explicit Fleet();

	void setShipPosition(int index, int x, int y, bool isVertical);
	void setIsDestroyed(int index, bool isDestroyed);
	void setShipX(int index, int x);
	void setShipY(int index, int y);

	int getShipX(int index) const;
	int getShipY(int index) const;
	int getSize(int index) const;
	bool getIsVertical(int index) const;
	bool getIsDestroyed(int index) const;

	bool checkHit(int index, int x, int y);
	bool searchForHit(int index);
};