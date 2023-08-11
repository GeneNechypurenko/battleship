#include "Menu.h"

bool Menu::selectDeploymentMethod()
{
    short x = 38, y = 12;
    int index = 0;
    int rows = 2;
    char keyHit;
    const char* menu[] = { "DEPLOY SHIPS BY YORSELF", "DEPLOY SHIPS AUTOMATICALLY" };

    rend.hideCursor(false);

    while (true)
    {
        system("cls");

        rend.outputColor(STANDART);
        rend.outputAt(x, y);
        cout << "HOW WOULD YOU LIKE TO DEPLOY YOUR FLEET?";

        for (int i = 0; i < rows; i++)
        {
            rend.outputAt(x + 5, y + 3 + i);
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