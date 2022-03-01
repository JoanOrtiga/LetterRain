#include "FallingLettersController.h"

#include "../FallingLetters/FallingLetter.h"

FallingLettersController::FallingLettersController()
{
	fallingLetters = new std::vector<FallingLetter>();
}

void FallingLettersController::Update()
{
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
