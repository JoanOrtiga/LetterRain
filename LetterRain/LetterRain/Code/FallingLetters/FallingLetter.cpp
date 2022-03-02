#include "FallingLetter.h"

#include <iostream>

#include "../ConsoleController.h";
#include "../Managers/TimeManager.h";

FallingLetter::FallingLetter(char _character, int _column)
{
	character = _character;
	position = { short(_column), (short)spawnRow};
	lastPosition = position;
}

void FallingLetter::Update()
{
	ConsoleController::SetCursorPosition(0,0);
	std::cout << lastPosition.X << " " << lastPosition.Y;

	lastPosition = position;
	position.Y++;
}

void FallingLetter::Draw()
{
	
	if (lastPosition.Y != position.Y)
	{
		ConsoleController::SetCursorPosition(lastPosition);
		std::cout << (char)250;
	}

	ConsoleController::SetCursorPosition(position);
	std::cout << character;
}
