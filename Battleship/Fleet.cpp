#include "Fleet.h"

Fleet::Ship::Ship(int size, string type)
	:
	size(size),
	type(type)
{
	shipX = -1;
	shipY = -1;
	isVertical = true;
	isActive = true;

	for (int i = 0; i < size; i++)
		depiction.push_back(DECK);
}

Fleet::Fleet()
{
	for (int i = 0; i < SHIPCOUNT; i++)
	{
		ships.push_back(Ship(DECKS[i], TYPES[i]));
	}
}

void Fleet::setShipPosition(int index, int x, int y, bool isVertical)
{
	ships[index].shipX = x;
	ships[index].shipY = y;
	ships[index].isVertical = isVertical;
}

int Fleet::getSize(int index) const
{
	return ships[index].size;
}

bool Fleet::checkHit(int index, int x, int y)
{
	if (ships[index].isVertical
		&& x == ships[index].shipX
		&& y >= ships[index].shipY
		&& y < ships[index].shipY + getSize(index))
	{
		ships[index].depiction[y - ships[index].shipY] = HIT;
		return true;
	}
	else if (!ships[index].isVertical
		&& y == ships[index].shipY
		&& x >= ships[index].shipX
		&& x < ships[index].shipX + getSize(index))
	{
		ships[index].depiction[x - ships[index].shipX] = HIT;
		return true;
	}
	return false;
}

void Fleet::printAll() const
{
	for (int i = 0; i < SHIPCOUNT; i++)
	{
		cout << ships[i].size << endl;
		cout << ships[i].type << endl;
		cout << ships[i].isActive << endl;
		cout << ships[i].isVertical << endl;
		cout << ships[i].shipX << endl;
		cout << ships[i].shipY << endl;

		cout << endl;
	}
}