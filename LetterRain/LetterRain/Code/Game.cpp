#include "Game.h"

#include <iomanip>
#include <iostream>

#include "ConsoleController.h"

Game::Game()
{
	Init();
}

void Game::Init() {
	ConsoleController::Init();

	fallingLettersController = new FallingLettersController();

	timeManager = new TimeManager();
	drawManager = new DrawManager(fallingLettersController);
	updateManager = new UpdateManager(fallingLettersController);
}

Game::~Game()
{
	delete timeManager;
	delete drawManager;
	delete updateManager;
	delete fallingLettersController;

	ConsoleController::Delete();
}

void Game::Loop() {
	while (true) {
		TimeLogic();
		Update();
		Draw();
	}
}

void Game::TimeLogic() {
	shouldDraw = timeManager->ShouldExecuteNextFrame();
}

void Game::Update() {
	updateManager->Update();
}

void Game::Draw() {
	if(shouldDraw)
	{
		drawManager->Draw();
	}
}
