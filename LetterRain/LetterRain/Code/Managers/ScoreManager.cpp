#include "ScoreManager.h"

void ScoreManager::AddScore()
{
	currentScore += 10;
}

void ScoreManager::SetNewHighScore()
{
	highScore = currentScore;
}

bool ScoreManager::IsHighScore() const
{
	return currentScore > highScore;
}
