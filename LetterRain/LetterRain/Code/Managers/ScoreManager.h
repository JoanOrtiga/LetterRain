#pragma once
class ScoreManager
{
private:
	int currentScore = 0;
	int highScore = 0;

public:
	void AddScore();
	void SetNewHighScore();
	bool IsHighScore() const;
};

