#include "FallingLettersController.h"

#include <iostream>

#include "../FallingLetters/FallingLetter.h"
#include "../Helper/RandomGeneratorManager.h"
#include "../ConsoleController.h"
#include "../Managers/TimeManager.h"

FallingLettersController::FallingLettersController()
{
	fallingLetters = new std::vector<FallingLetter*>();
}

FallingLettersController::~FallingLettersController()
{
}

void FallingLettersController::Update()
{
	if(TimeManager::instance.GetElapsedTime() % 5 == 0)
	{
		SpawnNewLetter();
	}

	/*for (auto& fallingLetter : *fallingLetters) {
		
		if(GetKeyState(fallingLetter.GetCharacter()) & 0x8000)
		{
			fallingLetter.LetterPressed();

			
		}
	}*/

	std::vector<FallingLetter>::iterator deleteElement;
	for (auto it = std::begin(*fallingLetters); it != std::end(*fallingLetters); ++it) {
		if (GetKeyState(it->GetCharacter()) & 0x8000)
		{
			it->LetterPressed();
			deleteElement = it;
		}
	}

	int t = deleteElement - fallingLetters->begin();

	fallingLetters->erase(t + fallingLetters->begin());


	for (auto& fallingLetter : *fallingLetters) {
		fallingLetter.Update();
	}
}

void FallingLettersController::Draw()
{
	for (auto& fallingLetter : *fallingLetters) {
		fallingLetter.Draw();
	}
}

void FallingLettersController::SpawnNewLetter()
{
	fallingLetters->push_back(*new FallingLetter(RandomGeneratorManager::GetRandomLetter(), RandomGeneratorManager::GetRandomNumberInRange(1, ConsoleController::consoleSizeX - 2)));
}
