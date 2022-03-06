#include "DrawManager.h"

#include <iostream>
#include <iomanip>

#include "TimeManager.h"
#include "../ConsoleController.h"

DrawManager::DrawManager(FallingLettersController* _fallingLettersController) : fallingLettersController(_fallingLettersController)
{
	NewGame();
}

void DrawManager::NewGame()
{
	ConsoleController::CLS();
	DrawPlayField();
}

void DrawManager::Draw()
{
	fallingLettersController->Draw();
	DrawTimePlayed();
}

void DrawManager::UpdateConsole()
{
    
}

void DrawManager::ResetColumn(short col, short currentRow)
{
	ConsoleController::SetCursorPosition(startSpawningRow, col);
	std::cout << flatHorizontal;

	for (short i = startSpawningRow+1; i <= currentRow; i++)
	{
		ConsoleController::SetCursorPosition(i, col);
		std::cout << " ";
	}
}

void DrawManager::DrawExplosion(COORD position, const char explosionShape[][3], int sizeX, int sizeY)
{
	for (short i = -(sizeY / 2); i < sizeY-1; i++)
	{
		for (int j = -(sizeX / 2); j < sizeX-1; ++j)
		{
			COORD drawPosition = position;
			drawPosition.X += j + (sizeX / 2) -1;
			drawPosition.Y += i + (sizeY / 2) -1;

			DrawProtected(explosionShape[j + (sizeX / 2)][i + (sizeY / 2)], drawPosition);
		}
	}
}

void DrawManager::DrawProtected(char character, COORD position)
{
	if (position.X < 1 || position.X > ConsoleController::consoleSizeX - 2 || position.Y <= startSpawningRow || position.Y >= ConsoleController::consoleSizeY - endRow)
		return;
	ConsoleController::SetCursorPosition(position);
	std::cout << character;
}

void DrawManager::DrawPlayField()
{
	//Draw Borders
	std::cout << cornerTopLeft;
	Fill(flatHorizontal, ConsoleController::consoleSizeX-1);
	std::cout << cornerTopRight;
	
	std::cout << flatVertical;
	ConsoleController::SetCursorPosition(1,ConsoleController::consoleSizeX-1);
	std::cout << flatVertical;
	
	std::cout << verticalWithRight;
	Fill(flatHorizontal, ConsoleController::consoleSizeX - 1);
	std::cout << verticalWithLeft;
	
	std::cout << verticalWithRight;
	Fill(flatHorizontal, ConsoleController::consoleSizeX - 1);
	std::cout << verticalWithLeft;
	
	for (short i = startSpawningRow+1; i < ConsoleController::consoleSizeY-1; i++)
	{
		std::cout << flatVertical;
		ConsoleController::SetCursorPosition(i, ConsoleController::consoleSizeX - 1);
		std::cout << flatVertical;
	};
	
	std::cout << cornerBottomLeft;
	Fill(flatHorizontal, ConsoleController::consoleSizeX - 1);
	std::cout << cornerBottomRight;

	ConsoleController::SetCursorPosition(ConsoleController::consoleSizeY - endRow, 1);
	Fill(wave, ConsoleController::consoleSizeX-1);

	//Draw Header
	ConsoleController::SetCursorPosition(scorePosition.X, scorePosition.Y);
	std::cout << scoreTxt;
	ConsoleController::SetCursorPosition(highScorePosition.X, ConsoleController::consoleSizeX - highScorePosition.Y);
	std::cout << highscoreTxt;

	ConsoleController::SetCursorPosition(timePlayedPosition.X, ConsoleController::consoleSizeX - timePlayedPosition.Y / 2 - timeTxt.length() +4);
	std::cout << timeTxt;
}

void DrawManager::Fill(char character, int fillAmount)
{
	std::cout << std::setfill(character) << std::setw(fillAmount-1) << character;
}

void DrawManager::DrawScore(int score, bool winning)
{
	winning ? ConsoleController::SetConsoleColor(ConsoleController::Colors::GREEN) : ConsoleController::SetConsoleColor(ConsoleController::Colors::RED);
	ConsoleController::SetCursorPosition(scorePosition.X, scorePosition.Y + scoreTxt.length());
	std::cout << score;
	ConsoleController::SetConsoleColor(ConsoleController::Colors::WHITE);
}

void DrawManager::DrawHighScore(int highScore)
{
	ConsoleController::SetCursorPosition(highScorePosition.X, ConsoleController::consoleSizeX - highScorePosition.Y + highscoreTxt.length());
	std::cout << highScore;
}

void DrawManager::DrawTimePlayed()
{
	ConsoleController::SetCursorPosition(highScorePosition.X, ConsoleController::consoleSizeX - timePlayedPosition.Y/2 + 4);
	std::cout << TimeManager::GetInstance().GetElapsedTime();
}

void DrawManager::DrawLetter(COORD position, char character, int barrierLevel = 0)
{
	for (short i = startSpawningRow; i < position.Y; i++)
	{
		ConsoleController::SetCursorPosition({position.X, i});
		std::cout << trailPoint;
	}

	if(barrierLevel > 0)
	{
		COORD leftBarrierPos = { position.X - 1, position.Y };
		COORD rightBarrierPos = { position.X + 1, position.Y };
		DrawProtected(barrierLeft, leftBarrierPos);
		DrawProtected(barrierRight, rightBarrierPos);
	}

	COORD cleanLeftBarrierPos = { position.X - 1, position.Y-1 };
	COORD cleanRightBarrierPos = { position.X + 1, position.Y-1 };
	DrawProtected(' ', cleanLeftBarrierPos);
	DrawProtected(' ', cleanRightBarrierPos);

	ConsoleController::SetCursorPosition(position);
	std::cout << character;
}



void DrawManager::GameLost()
{
	ConsoleController::SetCursorPosition(ConsoleController::consoleSizeY / 2, ConsoleController::consoleSizeX / 2 - 4);
	ConsoleController::SetConsoleColor(ConsoleController::Colors::RED);
	std::cout << "Game Lost";

	std::string exitMessage = "Press button 'C' to continue, or ESC, to close";
	ConsoleController::SetCursorPosition(ConsoleController::consoleSizeY / 2 + 2, ConsoleController::consoleSizeX / 2 - exitMessage.length() / 2);
	std::cout << exitMessage;

	ConsoleController::SetConsoleColor(ConsoleController::Colors::WHITE);
}

