#include "Sight.h"

HANDLE Sight::hSight = GetStdHandle(STD_OUTPUT_HANDLE);

Sight::Sight()
    :
    sight('+'),
    x(XMIN),
    y(YMIN)
{}

void Sight::outputSight() const
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(hSight, pos);
    cout << sight;
}

void Sight::clearSight() const
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(hSight, pos);
    cout << ' ';
}

void Sight::moveUp()
{
    clearSight();

    if (y > YMIN)
    {
       y--;
    }
}

void Sight::moveDown()
{
    clearSight();
    
    if (y < YMAX)
    {
        y++;
    }
}

void Sight::moveLeft()
{
    clearSight();
    
    if (x > XMIN)
    {
        x -= 1;
        x--;
    }
}

void Sight::moveRight()
{
    clearSight();

    if (x < XMAX)
    {
        x += 1;
        x++;
    }
}

void Sight::setDefault()
{
    y = YMIN;
    x = XMIN;
}

int Sight::convertToGameBoardX()
{
    if (x == XMIN)
    {
        int result = x - XMIN;
        return result;
    }
    else
    {
        int result = (x - XMIN) / 2;
        return result;
    }
}

int Sight::convertToGameBoardY()
{
    int result = y - YMIN;
    return result;
}