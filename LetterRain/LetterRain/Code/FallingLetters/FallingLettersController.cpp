#include "FallingLettersController.h"

#include <iostream>

#include "../FallingLetters/FallingLetter.h"
#include "../Helper/RandomGeneratorManager.h"
#include "../ConsoleController.h"
#include "../Managers/TimeManager.h"
#include "../Engine/InputController.h"
#include "../Game.h"

FallingLettersController::FallingLettersController() : fallingLetters(
	new FallingLetter*[ConsoleController::consoleSizeX]), explosions(new Explosion*[ConsoleController::consoleSizeX])
{
	for (short i = 0; i < ConsoleController::consoleSizeX; i++)
	{
		fallingLetters[i] = nullptr;
		explosions[i] = nullptr;
	}
}

FallingLettersController::~FallingLettersController()
{
	for (short i = 0; i < ConsoleController::consoleSizeX; ++i)
	{
		if (fallingLetters[i] != nullptr)
			delete fallingLetters[i];
		if (explosions[i] != nullptr)
			delete explosions[i];
	}

	delete[] fallingLetters;
	delete[] explosions;
}

void FallingLettersController::NewGame()
{
	for (short i = 0; i < ConsoleController::consoleSizeX; ++i)
	{
		if (fallingLetters[i] != nullptr)
		{
			delete fallingLetters[i];
			fallingLetters[i] = nullptr;
		}

		if (explosions[i] != nullptr)
		{
			delete explosions[i];
			explosions[i] = nullptr;
		}
	}
}


void FallingLettersController::DrawnUpdate()
{
	if (TimeManager::GetInstance().GetElapsedTime() % 1 == 0)
	{
		SpawnNewLetter();
	}

	for (short i = 0; i < ConsoleController::consoleSizeX; ++i)
	{
		if (explosions[i] != nullptr) {
			explosions[i]->DrawnUpdate();
		}
		if (fallingLetters[i] != nullptr)
			fallingLetters[i]->DrawnUpdate();
	}
}

void FallingLettersController::Update()
{
	for (short i = 0; i < ConsoleController::consoleSizeX; ++i)
	{
		if (explosions[i] != nullptr) {
			explosions[i]->Update();
		}

		if (fallingLetters[i] != nullptr) {
			fallingLetters[i]->Update();
		}
	}
}

void FallingLettersController::Draw()
{
	for (short i = 0; i < ConsoleController::consoleSizeX; i++)
	{
		if (explosions[i] != nullptr) {
			explosions[i]->Draw();
		}

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

	int barrierLevel = RandomGeneratorManager::GetRandomNumberInRange(0, 6) < 4 ? 0 : 1;

	fallingLetters[randomColumn] = new FallingLetter(this, RandomGeneratorManager::GetRandomLetter(), randomColumn, barrierLevel);
}

void FallingLettersController::SpawnExplosion(COORD position)
{
	explosions[position.X] = new Explosion(this, position);
}

void FallingLettersController::DestroyLetter(int col)
{
	delete fallingLetters[col];
	fallingLetters[col] = nullptr;
}

void FallingLettersController::DestroyExplosion(int col)
{
	delete explosions[col];
	explosions[col] = nullptr;
}

