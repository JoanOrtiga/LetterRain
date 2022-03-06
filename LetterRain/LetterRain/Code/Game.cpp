#include "Game.h"

#include <iomanip>
#include <iostream>
#include <conio.h>

#include "ConsoleController.h"
#include "Engine/InputController.h"

void Game::Init()
{
	ConsoleController::Init();

	fallingLettersController = new FallingLettersController();
	drawManager = new DrawManager(fallingLettersController);
	updateManager = new UpdateManager(fallingLettersController);
	scoreManager = new ScoreManager(drawManager);
}

Game::~Game()
{
	delete drawManager;
	delete updateManager;
	delete fallingLettersController;

	ConsoleController::Delete();
}

void Game::Loop() {
	bool exitGame = false;
	while(!exitGame)
	{
		while (!gameLost) {

			TimeLogic();
			Update();
			DrawnUpdate();
			Draw();

			if(InputController::IsKeyPressed(VK_ESCAPE))
			{
				exitGame = true;
				break;
			}
		}

		if (InputController::IsKeyPressed('C') || InputController::IsKeyPressed('c'))
		{
			NewGame();
		}
		else if (InputController::IsKeyPressed(VK_ESCAPE))
			exitGame = true;
	}
	
}

void Game::NewGame()
{
	gameLost = false;

	drawManager->NewGame();
	scoreManager->NewGame();
	fallingLettersController->NewGame();
}

void Game::Lost()
{
	gameLost = true;
	drawManager->GameLost();
	scoreManager->SetNewHighScore();
	shouldDraw = false;
}

void Game::TimeLogic() {
	shouldDraw = TimeManager::GetInstance().ShouldExecuteNextFrame();
}

void Game::Update() {
	updateManager->Update();

}

void Game::DrawnUpdate() {
	if (shouldDraw)
	{
		updateManager->DrawnUpdate();
	}
}

void Game::Draw() {
	if (shouldDraw)
	{
		drawManager->Draw();
	}
}
