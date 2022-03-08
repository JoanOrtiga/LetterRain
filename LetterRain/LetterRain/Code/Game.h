#pragma once

#include "Managers/TimeManager.h"
#include "Managers/DrawManager.h"
#include "Managers/UpdateManager.h"
#include "Managers/ScoreManager.h"
#include "FallingLetters/FallingLettersController.h"

class Game
{
public:
	

private:
	DrawManager* drawManager;
	UpdateManager* updateManager;
	FallingLettersController* fallingLettersController;
	ScoreManager* scoreManager;
	bool shouldDraw = false;
	bool gameLost = false;

public:
	void Init();
	void Loop();
	void NewGame();
	void Lost();
	DrawManager* GetDrawManager(){ return drawManager; }
	ScoreManager* GetScoreManager(){ return scoreManager; }

	static Game& GetInstance()
	{
		static Game instance;
		return instance;
	}

	

private:
	Game() {};
	~Game();
	Game(Game const&);              // Don't Implement.
	void operator=(Game const&); // Don't implement

	void TimeLogic();
	void Update();
	void DrawnUpdate();
	void Draw();
};

