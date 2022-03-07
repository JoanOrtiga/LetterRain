#pragma once

#include <windows.h>
#include "ConsoleController.fwd.h"
#include "Engine/Colors.h"

class Settings
{
public:
	static constexpr int cyclesPerFrame = 400;

	static constexpr int endGameRow = 3; //Minus ConsoleHeight.
	static constexpr int spawnRow = 3;
	static constexpr int shieldChance = 50;

	static constexpr COORD consoleBufferSize = { 94, 33 };
	static constexpr COORD consoleSize = { 780,570 };

	static constexpr Colors playfieldColor = Colors::WHITE;
	static constexpr Colors scoreWinningColor = Colors::GREEN;
	static constexpr Colors scoreLoseColor = Colors::RED;
	static constexpr Colors endGameTextcolor = Colors::RED;

	static constexpr Colors letterBarrier = Colors::CYAN;
	static constexpr Colors letterTrail = Colors::CYAN;
	static constexpr Colors letter = Colors::WHITE;

	static int GetLoseRow();
};

