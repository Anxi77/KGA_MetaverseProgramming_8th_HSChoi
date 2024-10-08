
#pragma region HowToConsoleBuffer
/*
#include <windows.h>
#include <iostream>

void SetConsoleSize(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void SetConsoleBufferSize(int width, int height)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD newSize = { static_cast<SHORT>(width), static_cast<SHORT>(height) };
    SetConsoleScreenBufferSize(hConsole, newSize);
}

void InitializeConsole(int width, int height)
{
    SetConsoleSize(width, height);
    SetConsoleBufferSize(width / 8, height / 16);  // 대략적인 비율, 필요에 따라 조정

    // 콘솔 창 크기 조정 비활성화
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

int main()
{
    InitializeConsole(800, 600);  // 원하는 크기로 설정 (예: 800x600)

    std::cout << "콘솔 크기가 조정되었습니다." << std::endl;

    // 여기에 게임 로직 추가

    return 0;
}
*/
/*
SetConsoleSize: 콘솔 창의 실제 크기를 설정합니다.
SetConsoleBufferSize: 콘솔의 버퍼 크기를 설정합니다. 이는 스크롤 없이 표시할 수 있는 텍스트의 양을 제어합니다.
InitializeConsole: 콘솔 창과 버퍼 크기를 설정하고, 사용자가 창 크기를 조정하지 못하도록 합니다.
main 함수에서 InitializeConsole(800, 600)을 호출하여 콘솔 창의 크기를 800x600 픽셀로 설정합니다. 이 값은 필요에 따라 조정할 수 있습니다.
주의사항:
이 코드는 Windows 운영 체제에서만 작동합니다.
콘솔 창의 크기는 화면 해상도와 DPI 설정에 따라 실제로 보이는 크기가 다를 수 있습니다.
버퍼 크기 설정은 대략적인 값이므로, 필요에 따라 조정해야 할 수 있습니다.
이 코드를 사용하면 프로그램 시작 시 콘솔 창의 크기를 원하는 대로 설정할 수 있으며, 사용자가 창 크기를 변경하지 못하도록 할 수 있습니다.
*/
#pragma endregion

#pragma region HowToConsoleBufferE.G)
/*
#include <windows.h>
#include <iostream>

void SetConsoleBufferSize(int width, int height)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD newSize = { static_cast<SHORT>(width), static_cast<SHORT>(height) };
    SetConsoleScreenBufferSize(hConsole, newSize);
}

void SetConsoleFontSize(int size)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
    fontInfo.dwFontSize.Y = size;  // 폰트 크기 설정
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
}

int main()
{
    // 콘솔 창 크기 설정
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 800, 600, TRUE);

    // 버퍼 크기를 매우 크게 설정
    SetConsoleBufferSize(200, 100);  // 가로 200, 세로 100 문자

    // 폰트 크기를 작게 설정
    SetConsoleFontSize(8);  // 8포인트 폰트

    // 테스트를 위한 출력
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 200; ++j) {
            std::cout << (j % 10);  // 0부터 9까지 반복 출력
        }
        std::cout << std::endl;
    }

    std::cout << "프로그램을 종료하려면 아무 키나 누르세요..." << std::endl;
    std::cin.get();

    return 0;
}
*/
/*
이 코드는 다음과 같은 효과를 만듭니다:
콘솔 창의 크기를 800x600 픽셀로 설정합니다.
콘솔 버퍼의 크기를 200x100 문자로 설정합니다. 이는 매우 큰 크기입니다.
폰트 크기를 8포인트로 설정하여 작게 만듭니다.
테스트를 위해 200x100 크기의 숫자 그리드를 출력합니다.
이렇게 하면 다음과 같은 결과를 얻을 수 있습니다:
1. 콘솔 창은 800x600 픽셀 크기를 유지합니다.
2. 버퍼 크기가 매우 크기 때문에, 한 화면에 더 많은 문자가 표시됩니다.
3. 폰트 크기가 작아져서 각 문자가 차지하는 공간이 줄어듭니다.
결과적으로 콘솔 창에서 더 많은 내용을 한 번에 볼 수 있게 되어, 마치 화면이 '축소'된 것처럼 보이게 됩니다.
주의할 점:
버퍼 크기와 폰트 크기의 조합에 따라 가독성이 떨어질 수 있습니다.
너무 극단적인 설정은 사용자 경험을 해칠 수 있으므로 적절한 균형을 찾는 것이 중요합니다.
이 방법은 Windows 운영 체제에서만 작동합니다.
이 기법을 사용하면 콘솔 창의 물리적 크기를 변경하지 않고도 더 많은 정보를 표시할 수 있어, 게임이나 복잡한 콘솔 애플리케이션에서 유용하게 활용할 수 있습니다.
*/
#pragma endregion

#include <windows.h>
#include <iostream>

using namespace std;

// 콘솔 폰트 크기 설정
void SetConsoleFontSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
    cfi.dwFontSize.X = width;
    cfi.dwFontSize.Y = height;
    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

// 콘솔 버퍼 크기 설정
void SetConsoleBufferSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize;
    bufferSize.X = width;
    bufferSize.Y = height;
    SetConsoleScreenBufferSize(hConsole, bufferSize);
}

// 콘솔 창 크기 설정
void SetConsoleWindowSize(int width, int height) {
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

void SetConsoleCursorPosition(float x, float y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void GetConsoleCursorPosition() 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    int cursorX = csbi.dwCursorPosition.X;
    int cursorY = csbi.dwCursorPosition.Y;

    std::cout << "현재 커서 위치: (" << cursorX << ", " << cursorY << ")" << std::endl;
}

void GridDisplay(int size)
{

    for (int i = 0; i < size; ++i) // Change 5 to size
    {
        SetConsoleCursorPosition(27, 1 + i * 4);
        for (int top = 0; top < size; ++top) // Change 5 to size
        {
            cout << "┏" << "━" << "━" << "━" << "━" << "┓";
        }
        SetConsoleCursorPosition(27, 2 + i * 4);
        for (int middle = 0; middle < size; ++middle) // Change 5 to size
        {
            cout << "│" << " " << " " << " " << " " << "│";
        }
        SetConsoleCursorPosition(27, 3 + i * 4);
        for (int middle = 0; middle < size; ++middle) // Change 5 to size
        {
            cout << "│" << " " << " " << " " << " " << "│";
        }
        SetConsoleCursorPosition(27, 4 + i * 4);
        for (int bottom = 0; bottom < size; ++bottom) // Change 5 to size
        {
            cout << "┗" << "━" << "━" << "━" << "━" << "┛";
        }
        cout << endl;
    }

    //for (int i = 0; i < 5; ++i)
    //{
    //    SetConsoleCursorPosition(27, 1 + i * 4);
    //    for (int top = 0; top < 5; ++top)
    //    {
    //        cout << "┏" << "━" << "━" << "━" << "━" << "┓";
    //    }
    //    SetConsoleCursorPosition(27, 2 + i * 4);
    //    for(int middle = 0; middle < 5; ++middle)
    //    {
    //        cout << "│" << " " << " " << " " << " " << "│";
    //    }
    //    SetConsoleCursorPosition(27, 3 + i * 4);
    //    for (int middle = 0; middle < 5; ++middle)
    //    {
    //        cout << "│" << " " << " " << " " << " " << "│";
    //    }
    //    SetConsoleCursorPosition(27, 4 + i * 4);
    //    for (int bottom = 0; bottom < 5; ++bottom)
    //    {
    //        cout << "┗" << "━" << "━" << "━" << "━" << "┛";
    //    }
    //    cout << endl;
    //}
    

}

void Borders()
{
    // 폰트 크기 설정 (너비, 높이)
    SetConsoleFontSize(75, 60);

    // 버퍼 크기 설정 (너비, 높이)
    SetConsoleBufferSize(80, 24);

    // 창 크기 설정 (너비, 높이)
    SetConsoleWindowSize(80, 24);

    Fullscreen();

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
}

void Overlay()
{
    SetConsoleCursorPosition(5, 1);
    GridDisplay(5);
    GetConsoleCursorPosition();
    SetConsoleCursorPosition(2, 1); // 커서 위치 설정
    cout << 2 << endl;
    SetConsoleCursorPosition(6, 1);
    cout << 2 << endl;
    SetConsoleCursorPosition(10, 1);
    cout << 2 << endl;
}

void Scores()
{
    SetConsoleCursorPosition(63, 1);
    cout << "┏" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "┓";
    SetConsoleCursorPosition(63, 2);
    cout << "│" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "│";
    SetConsoleCursorPosition(63, 3);
    cout << "│" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "│";
    SetConsoleCursorPosition(63, 4);
    cout << "│" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "│";
    SetConsoleCursorPosition(63, 5);
    cout << "┗" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "┛";
    SetConsoleCursorPosition(65, 2);
    cout << "Current Score" << endl;
    SetConsoleCursorPosition(66, 4);
    cout << "[" << " " << " " << " " << " " << " " << " " << " " << " " << " " << "]";
    SetConsoleCursorPosition(68, 4);
    cout <<" " << 12459/*Current Score*/ << endl;
    SetConsoleCursorPosition(63, 6);
    cout << "┏" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "┓";
    SetConsoleCursorPosition(63, 7);
    cout << "│" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "│";
    SetConsoleCursorPosition(63, 8);
    cout << "│" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "│";
    SetConsoleCursorPosition(63, 9);
    cout << "│" << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "│";
    SetConsoleCursorPosition(63, 10);
    cout << "┗" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "━" << "┛";
    SetConsoleCursorPosition(65, 7);
    cout << " " << " " << "Top Score" << endl;
    SetConsoleCursorPosition(66, 9);
    cout << "[" << " " << " " << " " << " " << " " << " " << " " << " " << " " << "]";
    SetConsoleCursorPosition(68, 9);
    cout << " " << 12459/*Top Score*/ << endl;
}

int main()
{
    Borders();
    GridDisplay(5);
    Scores();
    SetConsoleCursorPosition(120, 22);
}


