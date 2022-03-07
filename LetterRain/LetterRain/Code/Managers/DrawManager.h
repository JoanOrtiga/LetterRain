#pragma once

#include <xstring>

#include "../FallingLetters/FallingLettersController.h"
#include "../ConsoleController.h"
#include "../Settings.h"

class DrawManager
{
public:

private:
	const std::string scoreTxt = "SCORE: ";
	const std::string highscoreTxt = "HIGHSCORE: ";
	const std::string timeTxt = "Time Survived: ";
	const char cornerTopLeft = 201;		//╔
	const char cornerTopRight = 187;	//╗
	const char cornerBottomLeft = 200;	//╚
	const char cornerBottomRight = 188;	//╝

	const char flatVertical = 186;		//║
	const char flatHorizontal = 205;	//═
	
	const char verticalWithLeft = 185;	//╣
	const char verticalWithRight = 204;	//╠

	const char wave = 126;				//~
	const char trailPoint = 250;		//·
	const char barrierLeft = 91;		//[
	const char barrierRight = 93;		//]

	const short scoreRow = 1;
	const COORD scorePosition = {scoreRow,5};
	const COORD highScorePosition = { scoreRow,20}; //Column works - buffer lenght.
	const COORD timePlayedPosition = { scoreRow, ConsoleController::consoleSizeX}; //Column works - buffer lenght.

	const short startSpawningRow = Settings::spawnRow;
	const short endRow = Settings::endGameRow; //Minus ConsoleHeight.

	FallingLettersController* fallingLettersController;

public:
	DrawManager(FallingLettersController* _fallingLettersController);
	~DrawManager() = default;
	void NewGame();
	void Draw();
	void ResetColumn(short col, short currentRow);
	void DrawAt(std::string text, COORD position);
	void DrawAt(char character, int x, int y);
	void DrawAt(std::string text, int x, int y);
	void DrawScore(int score, bool winning);
	void DrawHighScore(int highScore);
	void DrawTimePlayed();
	void DrawLetter(COORD position, char character, int barrierLevel);
	void GameLost();
	void DrawExplosion(COORD position, const char explosionShape[][3], int sizeX, int sizeY);
	void DrawProtected(char character, COORD position);

private:
	void DrawPlayField();
	void Fill(char character, int fill);
	void DrawAt(char character, COORD position);

	void UpdateConsole();
};

