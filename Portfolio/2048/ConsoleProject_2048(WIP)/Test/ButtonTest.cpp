#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void SetConsoleCursorPosition(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int getCursorY()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    return csbi.dwCursorPosition.Y;
}


void GridSelect()
{
    SetConsoleCursorPosition(36, 12);
    cout << "START 4 X 4";
    SetConsoleCursorPosition(36, 14);
    cout << "START 5 X 5";
    SetConsoleCursorPosition(36, 16);
    cout << "START 6 X 6";
    SetConsoleCursorPosition(36, 18);
    cout << "QUIT";
    SetConsoleCursorPosition(36, 12);
}

int Button()
{
    int input = 0;
    bool SelectTrigger = true;
    int currentY = 12;
    while (SelectTrigger)
    {
        // Clear the arrow from all lines
        SetConsoleCursorPosition(33, 12);
        cout << "  ";
        SetConsoleCursorPosition(33, 14);
        cout << "  ";
        SetConsoleCursorPosition(33, 16);
        cout << "  ";
        SetConsoleCursorPosition(33, 18);
        cout << "  ";

        // Display the arrow on the current line
        SetConsoleCursorPosition(33, currentY);
        cout << "¢º";

        input = _getch(); // Read user input
        if (input == 224) // Arrow keys start with 224
        {
            input = _getch(); // Get the actual key code (72 for up, 80 for down)

            if (input == 72) // Arrow Up
            {
                if (currentY == 12)
                    currentY = 18; // Loop back to bottom
                else
                    currentY -= 2; // Move up
            }
            else if (input == 80) // Arrow Down
            {
                if (currentY == 18)
                    currentY = 12; // Loop back to top
                else
                    currentY += 2; // Move down
            }
        }
        else if (input == 32) // Space key to select
        {
            SelectTrigger = false;
            return currentY; // Return the Y position of the selected option
        }
        else
        {
            cout << "INVALID !!!" << endl;
        }
        
    }
}




int main()
{
    Button();
}