#include "FallingLetter.h"

#include <iostream>

#include "../Game.h"
#include "../ConsoleController.h"

FallingLetter::FallingLetter(char _character, int _column, FallingLettersController* _fallingLettersController) :
	character(_character), fallingLettersController(_fallingLettersController)
{
	position = { short(_column), (short)spawnRow};
	lastPosition = position;
}

void FallingLetter::Update()
{
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
	fallingLettersController->DeleteColumn(position.X, position.Y);
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



