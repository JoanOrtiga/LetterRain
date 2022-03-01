#pragma once
#include "Managers/TimeManager.h"
#include "Managers/DrawManager.h"

class Game
{
public:
	

private:
	TimeManager* timeManager;
	DrawManager* drawManager;
	bool shouldDraw = false;

public:
	Game();
	void Loop();

private:
	void TimeLogic();
	void Update();
	void Draw();
	void Init();

};

