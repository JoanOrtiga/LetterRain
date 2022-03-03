#include "DrawManager.h"

#include <iostream>
#include <iomanip>

#include "../ConsoleController.h"

DrawManager::DrawManager(FallingLettersController* _fallingLettersController) : fallingLettersController(_fallingLettersController)
{
    DrawPlayField();
}

void DrawManager::Draw()
{
	fallingLettersController->Draw();
}

void DrawManager::UpdateConsole()
{
    
}

void DrawManager::ResetColumn(short col, short currentRow)
{
	for (short i = 3; i < currentRow; i++)
	{
		ConsoleController::SetCursorPosition(i, col);
		std::cout << "";
	}
}

void DrawManager::DrawPlayField()
{

	//Draw Borders
	std::cout << cornerTopLeft;
	Fill(flatHorizontal, ConsoleController::consoleSizeX-1);
	std::cout << cornerTopRight;
	std::cout << flatVertical;
	ConsoleController::SetCursorPosition(1,ConsoleController::consoleSizeX-1);
	std::cout << flatVertical;
	std::cout << verticalWithRight;
	Fill(flatHorizontal, ConsoleController::consoleSizeX - 1);
	std::cout << verticalWithLeft;
	std::cout << verticalWithRight;
	Fill(flatHorizontal, ConsoleController::consoleSizeX - 1);
	std::cout << verticalWithLeft;

	for (short i = 4; i < ConsoleController::consoleSizeY-1; i++)
	{
		std::cout << flatVertical;
		ConsoleController::SetCursorPosition(i, ConsoleController::consoleSizeX - 1);
		std::cout << flatVertical;
	};

	std::cout << cornerBottomLeft;
	Fill(flatHorizontal, ConsoleController::consoleSizeX - 1);
	std::cout << cornerBottomRight;

	ConsoleController::SetCursorPosition(ConsoleController::consoleSizeY - 3, 1);
	Fill(wave, ConsoleController::consoleSizeX-1);

	//Draw Header
	ConsoleController::SetCursorPosition(1, 5);
	std::cout << "SCORE:";
	ConsoleController::SetCursorPosition(1, ConsoleController::consoleSizeX-20);
	std::cout << "RECORD:";
	
}

void DrawManager::Fill(char character, int fillAmount)
{
	std::cout << std::setfill(character) << std::setw(fillAmount-1) << character;
}

