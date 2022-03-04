#include "FallingLetter.h"

#include <iostream>

#include "../Game.h"
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

char FallingLetter::GetCharacter()
{
	return character;
}

void FallingLetter::LetterPressed()
{
	Game::instance.drawManager->ResetColumn(position.X, position.Y);
}

/*
bool FallingLetter::operator==(FallingLetter& rhs)
{
	if(position.X != rhs.position.X || position.Y != rhs.position.Y)
	{
		return false;
	}
		
	if (character != rhs.character)
		return false;

	return true;
}*/



