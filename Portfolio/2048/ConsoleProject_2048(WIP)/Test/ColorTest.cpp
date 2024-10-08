#include <iostream>
#include <windows.h>

using namespace std;

enum class ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Aqua = 3,
    Red = 4,
    Purple = 5,
    Yellow = 6,
    White = 7,
    Gray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightAqua = 11,
    LightRed = 12,
    LightPurple = 13,
    LightYellow = 14,
    BrightWhite = 15
};
void SetColor(ConsoleColor color) 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<int>(color));
}
void SetDefaultColor()
{
    SetColor(ConsoleColor::Gray);
}

void SetFontSize(int fontSize)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    GetCurrentConsoleFontEx(hConsole, FALSE, &cfi);

    cfi.dwFontSize.Y = fontSize; // Y축 폰트 사이즈 설정
    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

void PrintWithFontSize(const std::string& text, int fontSize)
{
    SetFontSize(fontSize); // 폰트 사이즈 설정
    std::cout << text; // 텍스트 출력
    SetFontSize(45);
}

int main()
{
    PrintWithFontSize("2", 90);
    cout << "2";
}