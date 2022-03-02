#include "FallingLettersController.h"

#include "../FallingLetters/FallingLetter.h"
#include "../Helper/RandomGeneratorManager.h"

FallingLettersController::FallingLettersController()
{
	fallingLetters = new std::vector<FallingLetter>();
	fallingLetters->push_back(*new FallingLetter(RandomGeneratorManager::GetRandomLetter(), 4));
}

FallingLettersController::~FallingLettersController()
{
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
