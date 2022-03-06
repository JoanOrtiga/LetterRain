#include "ScoreManager.h"

ScoreManager::ScoreManager(DrawManager* _drawManager)
{
	drawManager = _drawManager;
	
	NewGame();
}

ScoreManager::~ScoreManager()
{
	delete drawManager;
}

void ScoreManager::AddScore()
{
	currentScore += pointsXLetter;
	drawManager->DrawScore(currentScore, true);
}

void ScoreManager::SubScore()
{
	currentScore -= pointsXLetter;
	drawManager->DrawScore(currentScore, false);
}

void ScoreManager::SetNewHighScore()
{
	if (!IsHighScore())
		return;

	highScore = currentScore;
	drawManager->DrawHighScore(highScore);
}

bool ScoreManager::IsHighScore() const
{
	return currentScore > highScore;
}

void ScoreManager::NewGame()
{
	currentScore = 0;
	drawManager->DrawScore(currentScore, true);
	drawManager->DrawHighScore(highScore);
}
