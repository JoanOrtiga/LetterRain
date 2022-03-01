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

	timeManager = new TimeManager();
	drawManager = new DrawManager();

	(*timeManager).elapsedTime = 0;
}

void Game::Loop() {
	while (true) {
		TimeLogic();
		Update();
		Draw();
	}
}

void Game::TimeLogic() {
	shouldDraw = (*timeManager).ShouldExecuteNextFrame();
}

void Game::Update() {
	
}

void Game::Draw() {
	if(shouldDraw)
	{
		(*drawManager).Draw();
	}
}
