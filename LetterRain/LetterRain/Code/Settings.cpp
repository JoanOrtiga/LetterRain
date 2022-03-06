#include "Settings.h"

int Settings::endGameRow = 3; //Minus ConsoleHeight.
int Settings::spawnRow = 3; //Minus ConsoleHeight.

int Settings::GetLoseRow()
{
	return ConsoleController::consoleSizeY - endGameRow;
}