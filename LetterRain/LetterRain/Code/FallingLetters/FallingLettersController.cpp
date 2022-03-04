#include "FallingLettersController.h"

#include <iostream>

#include "../FallingLetters/FallingLetter.h"
#include "../Helper/RandomGeneratorManager.h"
#include "../ConsoleController.h"
#include "../Managers/TimeManager.h"
#include "../Engine/InputController.h"

FallingLettersController::FallingLettersController(DrawManager* drawManager) : fallingLetters(
	new FallingLetter*[ConsoleController::consoleSizeX]), drawManager(drawManager)
{
	for (short i = 0; i < ConsoleController::consoleSizeX; i++)
	{
		fallingLetters[i] = nullptr;
	}
}

FallingLettersController::~FallingLettersController()
{
	
}

void FallingLettersController::DrawnUpdate()
{
	if (TimeManager::instance.GetElapsedTime() % 5 == 0)
	{
		SpawnNewLetter();
	}

	for (short i = 0; i < ConsoleController::consoleSizeX; i++)
	{
		if (fallingLetters[i] != nullptr)
			fallingLetters[i]->Update();
	}
}

void FallingLettersController::DeleteColumn(int col, int row)
{
	drawManager->ResetColumn(col, row);
}

void FallingLettersController::Update()
{
	for (short i = 0; i < ConsoleController::consoleSizeX; i++)
	{
		ConsoleController::SetCursorPosition(0, 15);
		if (fallingLetters[i] != nullptr) {
			if (InputController::IsKeyPressed(fallingLetters[i]->GetCharacter()))
			{
				fallingLetters[i]->LetterPressed();
				delete fallingLetters[i];
				fallingLetters[i] = nullptr;
			}
		}
	}
}

void FallingLettersController::Draw()
{
	for (short i = 0; i < ConsoleController::consoleSizeX; i++)
	{
		if (fallingLetters[i] != nullptr) {
			fallingLetters[i]->Draw();
		}
	}
}

void FallingLettersController::SpawnNewLetter()
{
	int tries = 0;
	int randomColumn;

	do
	{
		randomColumn = RandomGeneratorManager::GetRandomNumberInRange(1, ConsoleController::consoleSizeX - 2);
		tries++;
	} while (tries <= ConsoleController::consoleSizeX-2 || fallingLetters[randomColumn] != nullptr);

	//Not able to generate letter bc playground is full
	if(tries == ConsoleController::consoleSizeX-2) 
		return;

	fallingLetters[randomColumn] = new FallingLetter(RandomGeneratorManager::GetRandomLetter(), randomColumn, this);
}


