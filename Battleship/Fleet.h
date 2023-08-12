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

const string TYPES[SHIPCOUNT] =
{
	"LINCORE",
	"FRIGATE", "FRIGATE",
	"CORVETTE", "CORVETTE", "CORVETTE",
	"BRIG", "BRIG", "BRIG", "BRIG"
};

class Fleet
{
private:

	struct Ship
	{
		int size;
		string type;
		int shipX;
		int shipY;
		bool isVertical; // true = vertical, false = horizontal
		bool isActive; // true = active, false = destroyed
		vector <char> depiction;

		Ship(int size, string type);
	};

	vector<Ship> ships;

public:
	explicit Fleet();

	void setShipPosition(int index, int x, int y, bool isVertical);
	int getSize(int index) const;
	bool checkHit(int index, int x, int y);

	void printAll() const;
};