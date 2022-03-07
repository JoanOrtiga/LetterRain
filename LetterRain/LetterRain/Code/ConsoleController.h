#pragma once

#include <windows.h>
#include <xstring>

#include "Settings.h"
#include "Engine/Colors.h"

class ConsoleController
{
public:
	static short consoleSizeX;
	static short consoleSizeY;

	static const short desiredConsoleSizeX = Settings::consoleSize.X;
	static const short desiredConsoleSizeY = Settings::consoleSize.Y;
	static const short desiredBufferSizeX = Settings::consoleBufferSize.X;
	static const short desiredBufferSizeY = Settings::consoleBufferSize.Y;

private:
	static HANDLE stdHandle;
	static CONSOLE_SCREEN_BUFFER_INFO csbi;


public:
	ConsoleController() = delete;

	static void Init();
	static void Delete();

	static void CLS();
	static void DrawAt(char character, COORD position);
	static void DrawAt(std::string text, COORD position);
	static void Fill(char character, int fillAmount);
	static void SetCursorPosition(short row, short col);
	static void SetCursorPosition(COORD coord);
	static void ResetColumn(short col);
	static void SetConsoleColor(Colors color);

private:
	static void GetWindowPos(int* x, int* y);

	static void HideCursor();
	static void SetConsoleSize();
	static bool HasConsoleChangedSize();
	
};

