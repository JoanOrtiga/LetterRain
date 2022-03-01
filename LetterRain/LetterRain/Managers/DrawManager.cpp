#include "DrawManager.h"

#include <iostream>
#include <iomanip>

#include "../ConsoleController.h"

DrawManager::DrawManager()
{
    DrawPlayField();
}

void DrawManager::Draw()
{
    
}


void DrawManager::UpdateConsole()
{
    
}

void DrawManager::DrawPlayField()
{
	std::cout << cornerTopLeft;
	Fill(flatHorizontal, ConsoleController::consoleSizeX-1);
	std::cout << cornerTopRight;
	std::cout << flatVertical;
	ConsoleController::SetCursorPosition(1,ConsoleController::consoleSizeX-1);
	std::cout << flatVertical;
	std::cout << verticalWithRight;
	ConsoleController::SetCursorPosition(2, ConsoleController::consoleSizeX - 1);
	std::cout << verticalWithLeft;

	for (short i = 1; i < ConsoleController::consoleSizeY-1; i++)
	{
		
	}
}

void DrawManager::Fill(char character, int fillAmount)
{
	std::cout << std::setfill(character) << std::setw(fillAmount);
}



