#pragma once

#include <windows.h>

class ConsoleController
{
public:
	static short consoleSizeX;
	static short consoleSizeY;

	static const short desiredConsoleSizeX = 785;
	static const short desiredConsoleSizeY = 650;
	static const short desiredBufferSizeX = 94;
	static const short desiredBufferSizeY = 33;

private:
	static HANDLE stdHandle;
	static CONSOLE_SCREEN_BUFFER_INFO csbi;


public:
	ConsoleController() = delete;

	static void Init();

	static void CLS();
	static void SetCursorPosition(short row, short col);
	static void SetCursorPosition(COORD coord);

private:
	static void GetWindowPos(int* x, int* y);

	static void HideCursor();
	static void SetConsoleSize();
	static bool HasConsoleChangedSize();



};

