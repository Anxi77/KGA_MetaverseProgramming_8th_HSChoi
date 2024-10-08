#include "ConsoleUtils.h"

namespace ConsoleUtils
{
    void SetColor(ConsoleColor color)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, static_cast<int>(color));
    }

    void DefaultColor()
    {
        SetColor(ConsoleColor::White);
    }

    void SetConsoleBufferSize(int width, int height)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD bufferSize;
        bufferSize.X = width;
        bufferSize.Y = height;
        SetConsoleScreenBufferSize(hConsole, bufferSize);
    }

    void SetConsoleWindowSize(int width, int height)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SMALL_RECT windowSize;
        windowSize.Left = 0;
        windowSize.Top = 0;
        windowSize.Right = width - 1;
        windowSize.Bottom = height - 1;
        SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
    }

    void Fullscreen()
    {
        SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
    }

    void SetConsoleFontSize(int width, int height)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
        GetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
        cfi.dwFontSize.X = width;
        cfi.dwFontSize.Y = height;
        SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
    }

    void GetConsoleCursorPosition()
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi);

        int cursorX = csbi.dwCursorPosition.X;
        int cursorY = csbi.dwCursorPosition.Y;

        std::cout << "커서 위치 (" << cursorX << ", " << cursorY << ")" << std::endl;
    }

    void CursorView()
    {
        CONSOLE_CURSOR_INFO cursorInfo = { 0, };
        cursorInfo.dwSize = 1;
        cursorInfo.bVisible = FALSE;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    }

    void gotoXY()
    {
        int input = 0;
        while (input != 97)
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            int cursorX = csbi.dwCursorPosition.X;
            int cursorY = csbi.dwCursorPosition.Y;
            input = _getch();
            if (input == 224)
            {
                input = _getch();
                switch (input)
                {
                case 72:
                    SetConsoleCursorPosition(cursorX, cursorY - 1);
                    break;
                case 80:
                    SetConsoleCursorPosition(cursorX, cursorY + 1);
                    break;
                case 77:
                    SetConsoleCursorPosition(cursorX + 1, cursorY);
                    break;
                case 75:
                    SetConsoleCursorPosition(cursorX - 1, cursorY);
                    break;
                default:
                    cout << "INVALID!" << endl;
                    break;
                }
            }
            else if (input == 97)
            {
                cout << "커서 위치 (" << cursorX << ", " << cursorY << ")" << endl;
            }
        }
    }

    void SetConsoleCursorPosition(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        ::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void ColoredPrint(const string& text, ConsoleColor color)
    {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        ConsoleColor originalColor = ConsoleColor::White;
        SetColor(color);
        cout << text;
        SetColor(originalColor);
    }

    void Borders()
    {

        SetColor(ConsoleColor::LightYellow);
        SetConsoleCursorPosition(0, 0);
        for (int y = 0; y < 23; ++y)
        {
            if (y == 0 || y == 22)
            {
                for (int x = 0; x < 41; ++x)
                {
                    cout << "▣";
                }
                cout << endl;
            }
            else {
                for (int x = 0; x < 80; ++x)
                {
                    if (x != 0 && x != 79)
                    {
                        cout << " ";
                    }
                    else if (x == 0)
                    {
                        cout << "▣";
                    }
                    else if (x == 79)
                    {
                        cout << "▣";
                        cout << endl;
                    }
                }
            }
        }
        SetConsoleCursorPosition(0, 0);
        DefaultColor();
    }

    void SetColorFromHex(const string& hexColor)
    {
        // 헥스 문자열을 정수로 변환
        unsigned int hexValue;
        stringstream ss;
        ss << std::hex << hexColor.substr(1); // '#' 제거
        ss >> hexValue;

        // RGB 값을 추출
        int r = (hexValue >> 16) & 0xFF;
        int g = (hexValue >> 8) & 0xFF;
        int b = hexValue & 0xFF;

        // 색상 설정 (콘솔 색상은 0-15의 인덱스를 사용)
        int redIndex = r / 256.0 * 15;
        int greenIndex = g / 256.0 * 15;
        int blueIndex = b / 256.0 * 15;

        // 색상 인덱스를 WORD로 결합
        WORD color = (redIndex << 4) | (greenIndex << 2) | blueIndex;

        // 콘솔 색상 설정
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
}