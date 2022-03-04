#pragma once

#include <vector>
#include "FallingLetter.h"
#include "../Engine/IGameObject.h"
#include "../Managers/DrawManager.h"

class FallingLettersController : public IGameObject
{
public:
	
private:
	FallingLetter** fallingLetters;
	DrawManager* drawManager;
	
public:
	FallingLettersController(DrawManager* drawManager);
	~FallingLettersController() override;
	void Update() override;
	void Draw() override;
	void SpawnNewLetter();
	void DrawnUpdate() override;
	void DeleteColumn(int col, int row);

private:

};

