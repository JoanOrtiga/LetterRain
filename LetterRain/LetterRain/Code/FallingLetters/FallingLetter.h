#pragma once

#include <Windows.h> //This has to remain here bc wincontypes uses windows.h
#include <wincontypes.h>
#include "../Engine/IGameObject.h"

class FallingLetter : public IGameObject
{
public:

private:
	char character = 0;
	COORD lastPosition = {};
	COORD position = {};
	const int spawnRow = 3;
	
public:
	FallingLetter(char _character, int _column);
	void Update() override;
	void Draw() override;
	char GetCharacter();
	void LetterPressed();

private:
};

