#pragma once

#include "../FallingLetters/FallingLettersController.h"
#include "TimeManager.h";

class UpdateManager
{
public:

private:
	TimeManager* timeManager;
	FallingLettersController* fallingLettersController;

public:
	UpdateManager(FallingLettersController* _fallingLettersController, TimeManager* _timeManager);
	void Update();

private:
	
};

