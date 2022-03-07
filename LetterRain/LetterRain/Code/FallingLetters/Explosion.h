#pragma once

#include <Windows.h>
#include <wincon.h>
#include "../Engine/IGameObject.h"
#include "FallingLettersController.fwd.h"

class Explosion : public IGameObject
{
public:

private:
	#define	MAX_STATES 4
	const int maxStates = MAX_STATES;
	const char explosionShape[MAX_STATES][3][3] =
	{
		{						
			{32,32,32},
			{32,111,32},
			{32,32,32}
		},
		{
			{92,124,47},
			{45,111,45},
			{47,124,92}
		},
		{
			{92,124,47},
			{45,32,45},
			{47,124,92}
		},
		{
			{32,32,32},
			{32,32,32},
			{32,32,32}
		}
		/*	{
			{' ', ' ', ' '},
			{' ', 'O', ' '},
			{' ', ' ', ' '}
		},
		{
			{'\\', '|', '/'},
			{'-', 'O', '-'},
			{'/', '|', '\\'}
		},
		{
			{'\\', '|', '/'},
			{'-', ' ', '-'},
			{'/', '|', '\\'}
		},
		{
			{' ', ' ', ' '},
			{' ', ' ', ' '},
			{' ', ' ', ' '}
		}
	 */
	};

	int currentState = -1; //Initial state
	COORD position;
	FallingLettersController* fallingLettersController;

public:
	Explosion(FallingLettersController* _fallingLettersController, COORD _position);
	void DrawnUpdate() override;
	void Update() override;
	void Draw() override;
};

