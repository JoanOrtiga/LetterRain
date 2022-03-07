#include "Settings.h"

#include "ConsoleController.h"
int Settings::GetLoseRow()
{
	return ConsoleController::consoleSizeY - endGameRow;
}
