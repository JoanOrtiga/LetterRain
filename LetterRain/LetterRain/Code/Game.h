#pragma once
#include "Managers/TimeManager.h"
#include "Managers/DrawManager.h"
#include "Managers/UpdateManager.h"
#include "FallingLetters/FallingLettersController.h"
#include "Engine/InputController.h"

class Game
{
public:

private:
	DrawManager* drawManager;
	TimeManager* timeManager;
	UpdateManager* updateManager;
	FallingLettersController* fallingLettersController;
	bool shouldDraw = false;

public:
	Game();
	~Game();
	void Loop();

private:
	void TimeLogic();
	void Update();
	void DrawnUpdate();
	void Draw();
};

