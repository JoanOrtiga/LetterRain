#pragma once

#include <Windows.h> //This has to remain here bc wincontypes uses windows.h
#include <wincontypes.h>
#include "../Engine/IGameObject.h"
#include "../Settings.h"
#include "FallingLettersController.fwd.h"

#include "../Engine/InputController.h"

class FallingLetter : public IGameObject
{
public:

private:
	int barrierLevel = 0;
	char character = 0;
	COORD position = {};
	const int spawnRow = Settings::spawnRow;
	FallingLettersController* fallingLettersController;
	bool unpressed = true;
	
public:
	FallingLetter(FallingLettersController* fallingLettersController, char _character, int _column, int _barrierLevel);
	void DrawnUpdate() override;
	~FallingLetter() override = default;
	void Update() override;
	void Draw() override;
	char GetCharacter();
	void LetterPressed();
private:
};

