#include "ConsoleController.h"

#include <iostream>

short ConsoleController::consoleSizeX = 0;
short ConsoleController::consoleSizeY = 0;

HANDLE ConsoleController::stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO ConsoleController::csbi;

void ConsoleController::Init()
{
    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = desiredBufferSizeY - 1;
    Rect.Right = desiredBufferSizeX - 1;

    SetConsoleWindowInfo(stdHandle, TRUE, &Rect);
    SetConsoleScreenBufferSize(stdHandle, { desiredBufferSizeX, desiredBufferSizeY });

    consoleSizeX = desiredBufferSizeX;
    consoleSizeY = desiredBufferSizeY;

    HideCursor();
}

void ConsoleController::Delete()
{
    delete stdHandle;
}

void ConsoleController::SetConsoleSize()
{
    HWND hwnd = GetConsoleWindow();
    int x, y;
    GetWindowPos(&x, &y);
    MoveWindow(hwnd, x, y, desiredConsoleSizeX, desiredConsoleSizeY,  TRUE);
}

void ConsoleController::GetWindowPos(int* x, int* y) {
    RECT rect = { NULL };
    if (GetWindowRect(GetConsoleWindow(), &rect)) {
        *x = rect.left;
        *y = rect.top;
    }
}

void ConsoleController::HideCursor()
{
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 50;
    GetConsoleCursorInfo(stdHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(stdHandle, &cursorInfo);
}

bool ConsoleController::HasConsoleChangedSize()
{
    //If Console size changed, re-arrange game
    GetConsoleScreenBufferInfo(stdHandle, &csbi);
    if (consoleSizeX != csbi.dwSize.X || consoleSizeY != csbi.dwSize.Y)
    {
        consoleSizeX = csbi.dwSize.X;
        consoleSizeY = csbi.dwSize.Y;

        CLS();
        HideCursor();

        return true;
    }

    return false;
}

void ConsoleController::SetCursorPosition(short row, short col)
{
    std::cout.flush();
    SetConsoleCursorPosition(stdHandle, { col,row });
}

void ConsoleController::SetCursorPosition(COORD coord)
{
    std::cout.flush();
    SetConsoleCursorPosition(stdHandle, { coord.X,coord.Y });
}

void ConsoleController::CLS()
{
    const COORD topLeft = { 0, 0 };

    std::cout.flush();

    DWORD length = consoleSizeX * consoleSizeY;
    DWORD written;

    // Flood-fill the console with spaces to clear it
    FillConsoleOutputCharacter(stdHandle, TEXT(' '), length, topLeft, &written);
    // This clears all background colour formatting
    FillConsoleOutputAttribute(stdHandle, csbi.wAttributes, length, topLeft, &written);
    // Move the cursor back to the top left for start again
    SetCursorPosition(topLeft);
}
