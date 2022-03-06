#include "Explosion.h"

#include <iostream>

#include "../Game.h"

Explosion::Explosion(FallingLettersController* _fallingLettersController, COORD _position) : position(_position),
	fallingLettersController(_fallingLettersController)
{
}

void Explosion::DrawnUpdate()
{
	currentState++;
}

void Explosion::Update()
{
	if (currentState >= maxStates-1)
	{
		fallingLettersController->DestroyExplosion(position.X);
	}
}

void Explosion::Draw()
{
	Game::GetInstance().GetDrawManager()->DrawExplosion(position, explosionShape[currentState], 3, 3);
}
