#pragma once

#include "../FallingLetters/FallingLettersController.h"

class DrawManager
{
public:

private:
	const char cornerTopLeft = 201;		//╔
	const char cornerTopRight = 187;	//╗
	const char cornerBottomLeft = 200;	//╚
	const char cornerBottomRight = 188;	//╝

	const char flatVertical = 186;		//║
	const char flatHorizontal = 205;	//═
	
	const char verticalWithLeft = 185;	//╣
	const char verticalWithRight = 204;	//╠

	const char wave = 126;				//~

	FallingLettersController* fallingLettersController;

public:
	DrawManager(FallingLettersController* _fallingLettersController);
	void Draw();
	void ResetColumn(short col, short currentRow);

private:
	void DrawPlayField();
	void Fill(char character, int fill);

	void UpdateConsole();
};

