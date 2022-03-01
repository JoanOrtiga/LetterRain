#pragma once
#include "../FallingLetters/FallingLettersController.h"

class UpdateManager
{
public:

private:
	FallingLettersController* fallingLettersController;

public:
	UpdateManager(FallingLettersController* _fallingLettersController);
	void Update();

private:
	
};

