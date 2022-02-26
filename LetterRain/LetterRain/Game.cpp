#include "Game.h"

#include <iomanip>
#include <iostream>


void Game::Loop() {

	timeManager.elapsedTime = 0;
	drawManager;

	while (true) {
		TimeLogic();
		Update();
		Draw();
	}
}

void Game::TimeLogic() {
	shouldDraw = timeManager.ShouldExecuteNextFrame();
}

void Game::Update() {
	
}

void Game::Draw() {
	if(shouldDraw)
	{
		drawManager.Draw();
	}
}
