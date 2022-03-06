#include "FallingLetter.h"

#include "../Game.h"

FallingLetter::FallingLetter(FallingLettersController* _fallingLettersController, char _character, int _column, int _barrierLevel) :
	character(_character), fallingLettersController(_fallingLettersController), barrierLevel(_barrierLevel)
{
	position = { short(_column), (short)spawnRow};
}


void FallingLetter::DrawnUpdate()
{
	position.Y++;

	if(position.Y >= Settings::GetLoseRow())
	{
		Game::GetInstance().Lost();
	}
}

void FallingLetter::Update()
{
	if (InputController::IsKeyPressed(character) && unpressed)
	{
		unpressed = false;
		if(barrierLevel > 0)
		{
			barrierLevel--;
		}
		else
		{
			LetterPressed();
		}
	}
	else if(!InputController::IsKeyPressed(character))
	{
		unpressed = true;
	}
}

void FallingLetter::Draw()
{
	Game::GetInstance().GetDrawManager()->DrawLetter(position, character, barrierLevel);
}

char FallingLetter::GetCharacter()
{
	return character;
}

void FallingLetter::LetterPressed()
{
	Game::GetInstance().GetDrawManager()->ResetColumn(position.X, position.Y);
	fallingLettersController->SpawnExplosion(position);
	Game::GetInstance().GetScoreManager()->AddScore();
	fallingLettersController->DestroyLetter(position.X);


}

