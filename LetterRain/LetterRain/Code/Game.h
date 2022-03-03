#pragma once
#include "Managers/TimeManager.h"
#include "Managers/DrawManager.h"
#include "Managers/UpdateManager.h"
#include "FallingLetters/FallingLettersController.h"

class Game
{
public:
	static Game instance;

	DrawManager* drawManager{};

private:
	TimeManager* timeManager{};
	UpdateManager* updateManager{};
	FallingLettersController* fallingLettersController{};
	bool shouldDraw = false;

public:
	Game();
	~Game();
	void Loop();

private:
	void TimeLogic();
	void Update();
	void Draw();
	void Init();
	
};

