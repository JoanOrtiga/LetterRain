#include "DrawManager.h"

#include <iostream>
#include <iomanip>
#include <string>

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
	DrawAt(flatHorizontal, col, startSpawningRow);

	for (short i = startSpawningRow+1; i <= currentRow; i++)
	{
		DrawAt(' ', col, i);
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
	DrawAt(character, position);
}

void DrawManager::DrawPlayField()
{
	//Draw Borders
	std::cout << cornerTopLeft;
	Fill(flatHorizontal, ConsoleController::consoleSizeX-1);
	std::cout << cornerTopRight;

	for (short i = 1; i < startSpawningRow-1; i++)
	{
		std::cout << flatVertical;
		ConsoleController::SetCursorPosition(i, ConsoleController::consoleSizeX - 1);
		std::cout << flatVertical;
	}

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
	DrawAt(scoreTxt, scorePosition.Y, scorePosition.X);
	DrawAt(highscoreTxt, (ConsoleController::consoleSizeX - highScorePosition.Y), highScorePosition.X);
	DrawAt(timeTxt, (ConsoleController::consoleSizeX - timePlayedPosition.Y / 2 - timeTxt.length() + 4),  timePlayedPosition.X);
}

void DrawManager::DrawScore(int score, bool winning)
{
	winning ? ConsoleController::SetConsoleColor(Settings::scoreWinningColor) : ConsoleController::SetConsoleColor(Settings::scoreLoseColor);
	DrawAt(std::to_string(score), scorePosition.Y + scoreTxt.length(), scorePosition.X);
	ConsoleController::SetConsoleColor(Settings::playfieldColor);
}

void DrawManager::DrawHighScore(int highScore)
{
	DrawAt(std::to_string(highScore),ConsoleController::consoleSizeX - highScorePosition.Y + highscoreTxt.length(), highScorePosition.X);
}

void DrawManager::DrawTimePlayed()
{
	DrawAt(std::to_string(TimeManager::GetInstance().GetElapsedTime()), ConsoleController::consoleSizeX - timePlayedPosition.Y / 2 + 4, highScorePosition.X);
}

void DrawManager::DrawLetter(COORD position, char character, int barrierLevel = 0)
{
	ConsoleController::SetConsoleColor(Settings::letterTrail);
	for (short i = startSpawningRow; i < position.Y; i++)
	{
		ConsoleController::SetCursorPosition({position.X, i});
		std::cout << trailPoint;
	}

	ConsoleController::SetConsoleColor(Settings::letterBarrier);
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

	ConsoleController::SetConsoleColor(Settings::letter);
	
	DrawAt(character, position);

	ConsoleController::SetConsoleColor(Settings::playfieldColor);
}

void DrawManager::GameLost()
{
	ConsoleController::SetCursorPosition(ConsoleController::consoleSizeY / 2, ConsoleController::consoleSizeX / 2 - 4);
	ConsoleController::SetConsoleColor(Settings::endGameTextcolor);
	std::cout << "Game Lost";

	std::string exitMessage = "Press button 'C' to continue, or ESC, to close";
	ConsoleController::SetCursorPosition(ConsoleController::consoleSizeY / 2 + 2, ConsoleController::consoleSizeX / 2 - exitMessage.length() / 2);
	std::cout << exitMessage;

	ConsoleController::SetConsoleColor(Settings::playfieldColor);
}


void DrawManager::Fill(char character, int fillAmount)
{
	ConsoleController::Fill(character, fillAmount);
}

void DrawManager::DrawAt(char character, COORD position)
{
	ConsoleController::DrawAt(character, position);
}

void DrawManager::DrawAt(std::string text, COORD position)
{
	ConsoleController::DrawAt(text, position);
}

void DrawManager::DrawAt(char character, int x, int y)
{
	ConsoleController::DrawAt(character, { short(x), short(y) });
}

void DrawManager::DrawAt(std::string text, int x, int y)
{
	ConsoleController::DrawAt(text, { short(x), short(y) });
}