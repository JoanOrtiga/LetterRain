#pragma once

#include <vector>
#include "FallingLetter.h"
#include "../Engine/IGameObject.h"

class FallingLettersController : public IGameObject
{
public:
	
private:
	std::vector<FallingLetter*>* fallingLetters;
	
public:
	FallingLettersController();
	~FallingLettersController() override;
	void Update() override;
	void Draw() override;
	void SpawnNewLetter();

private:

};

