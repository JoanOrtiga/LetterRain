#pragma once

#include "DrawManager.h"

class ScoreManager
{
private:
	int currentScore = 0;
	int highScore = 0;
	DrawManager* drawManager;
	const int pointsXLetter = 1;

public:
	ScoreManager(DrawManager* _drawManager);
	~ScoreManager();
	void AddScore();
	void SubScore();
	void SetNewHighScore();
	bool IsHighScore() const;
	void NewGame();
};

