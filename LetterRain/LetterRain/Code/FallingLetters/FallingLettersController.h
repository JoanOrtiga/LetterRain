#pragma once
#include "FallingLettersController.fwd.h"

#include <vector>
#include "FallingLetter.h"
#include "../Engine/IGameObject.h"
#include "Explosion.h"

class FallingLettersController : public IGameObject
{
public:
	
private:
	FallingLetter** fallingLetters;
	Explosion** explosions;
	
public:
	FallingLettersController();
	~FallingLettersController() override;
	void NewGame();
	void Update() override;
	void Draw() override;
	void SpawnNewLetter();
	void SpawnExplosion(COORD position);
	void DestroyLetter(int col);
	void DestroyExplosion(int col);
	void DrawnUpdate() override;

private:

};

