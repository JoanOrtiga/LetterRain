#include "Game.h"

#include <iomanip>
#include <iostream>

#include "ConsoleController.h"

Game::Game()
{
	ConsoleController::Init();

	fallingLettersController = new FallingLettersController(drawManager);
	timeManager = new TimeManager();
	drawManager = new DrawManager(fallingLettersController);
	updateManager = new UpdateManager(fallingLettersController, timeManager);
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
		DrawnUpdate();
		Draw();
	}
}

void Game::TimeLogic() {
	shouldDraw = timeManager->ShouldExecuteNextFrame();
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
