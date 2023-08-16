#include "Menu.h"

bool Menu::selectGameMode()
{
    short x = 46, y = 12;
    int index = 0;
    int rows = 2;
    char keyHit;
    const char* menu[] = { "PLAYER VS OPPONENT", "DEMONSTRATION MODE" };

    rend.hideCursor(false);

    while (true)
    {
        system("cls");

        rend.outputColor(STANDART);
        rend.outputAt(x, y);
        cout << "SELECT GAME MODE";

        for (int i = 0; i < rows; i++)
        {
            rend.outputAt(x - 4, y + 3 + i);
            rend.outputColor(STANDART);

            if (i == index)
            {
                cout << " " << MARKER << " ";
                rend.outputColor(HIGHLIGHT);
            }
            else
            {
                cout << "   ";
                rend.outputColor(STANDART);
            }

            cout << menu[i] << endl;
        }

        keyHit = _getch();

        switch (keyHit)
        {
        case UP:
            index = (index - 1 + rows) % rows;
            break;
        case DOWN:
            index = (index + 1) % rows;
            break;
        case ENTER:
            return index == 0;
        }
    }
}

bool Menu::selectDeploymentMethod()
{
    short x = 38, y = 12;
    int index = 0;
    int rows = 2;
    char keyHit;
    const char* menu[] = { "DEPLOY SHIPS BY YORSELF", "DEPLOY SHIPS AUTOMATIC" };

    rend.hideCursor(false);

    while (true)
    {
        system("cls");

        rend.outputColor(STANDART);
        rend.outputAt(x, y);
        cout << "HOW WOULD YOU LIKE TO DEPLOY YOUR FLEET?";

        for (int i = 0; i < rows; i++)
        {
            rend.outputAt(x + 4, y + 3 + i);
            rend.outputColor(STANDART);

            if (i == index)
            {
                cout << " " << MARKER << " ";
                rend.outputColor(HIGHLIGHT);
            }
            else
            {
                cout << "   ";
                rend.outputColor(STANDART);
            }

            cout << menu[i] << endl;
        }

        keyHit = _getch();

        switch (keyHit)
        {
        case UP:
            index = (index - 1 + rows) % rows;
            break;
        case DOWN:
            index = (index + 1) % rows;
            break;
        case ENTER:
            return index == 0;
        }
    }
}

void Menu::counterPlayerHits(int countHits, int winCondition)
{
    short x = 37, y = 6;
    rend.outputAt(x, y);
    rend.outputColor(GREEN);
    cout << "TARGETS LEFT: " << winCondition - countHits;
    cout << "                   ";
    rend.outputColor(STANDART);
}

void Menu::counterOpponetsHits(int countHits, int winCondition)
{
    short x = 63, y = 6;
    rend.outputAt(x, y);
    rend.outputColor(RED);
    cout << "TARGETS LEFT: " << winCondition - countHits;
    cout << "                   ";
    rend.outputColor(STANDART);
}

void Menu::declareWinnerPlayer(int countHits, int winCondition)
{
    if (countHits == winCondition)
    {
        short x = 38, y = 14;

        system("cls");

        rend.outputAt(x, y);
        rend.outputColor(HIGHLIGHT);
        cout << "CONGRATULATIONS! YOU HAVE WON THE BATTLESHIP GAME!";
        rend.outputColor(STANDART);

        rend.outputAt(0, 28);
        system("pause");
    }
}

void Menu::declareWinnerOpponent(int countHits, int winCondition)
{
    if (countHits == winCondition)
    {
        short x = 40, y = 14;

        system("cls");

        rend.outputAt(x, y);
        rend.outputColor(HIGHLIGHT);
        cout << "YOUR OPPONENT HAS WON THE BATTLESHIP GAME";
        rend.outputColor(STANDART);

        rend.outputAt(0, 28);
        system("pause");
    }
}
