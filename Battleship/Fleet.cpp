#include "Fleet.h"

Fleet::Ship::Ship(int size)
	:
	size(size)
{
	shipX = -1;
	shipY = -1;
	isVertical = true;
	isDestroyed = false;

	for (int i = 0; i < size; i++)
		depiction.push_back(DECK);
}

Fleet::Fleet()
{
	for (int i = 0; i < SHIPCOUNT; i++)
	{
		ships.push_back(Ship(DECKS[i]));
	}
}

void Fleet::setShipPosition(int index, int x, int y, bool isVertical)
{
	ships[index].shipX = x;
	ships[index].shipY = y;
	ships[index].isVertical = isVertical;
}

void Fleet::setIsDestroyed(int index, bool isDestroyed)
{
	ships[index].isDestroyed = true;
}

void Fleet::setShipX(int index, int x)
{
	ships[index].shipX = x;
}

void Fleet::setShipY(int index, int y)
{
	ships[index].shipY = y;
}

int Fleet::getShipX(int index) const
{
	return ships[index].shipX;
}

int Fleet::getShipY(int index) const
{
	return ships[index].shipY;
}

int Fleet::getSize(int index) const
{
	return ships[index].size;
}

bool Fleet::getIsVertical(int index) const
{
	return ships[index].isVertical;
}

bool Fleet::getIsDestroyed(int index) const
{
	return ships[index].isDestroyed;
}

bool Fleet::checkHit(int index, int x, int y)
{
    if (ships[index].isVertical && x == ships[index].shipX && y >= ships[index].shipY && y < ships[index].shipY + getSize(index))
    {
        ships[index].depiction[y - ships[index].shipY] = HIT;

        ships[index].isDestroyed = true;
        for (int i = 0; i < getSize(index); i++)
        {
            if (ships[index].depiction[i] == DECK)
            {
                ships[index].isDestroyed = false;
            }
        }

        return true;
    }
    else if (!ships[index].isVertical && y == ships[index].shipY && x >= ships[index].shipX && x < ships[index].shipX + getSize(index))
    {
        ships[index].depiction[x - ships[index].shipX] = HIT;

        ships[index].isDestroyed = true;
        for (int i = 0; i < getSize(index); i++)
        {
            if (ships[index].depiction[i] == DECK)
            {
                ships[index].isDestroyed = false;
            }
        }

        return true;
    }

    return false;
}

bool Fleet::searchForHit(int index)
{
	for (int i = 0; i < getSize(index); i++)
	{
		if (ships[index].depiction[i] == HIT && !ships[index].isDestroyed)
		{
			return true;
		}
	}
	return false;
}