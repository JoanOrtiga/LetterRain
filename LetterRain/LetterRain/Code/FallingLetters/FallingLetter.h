#pragma once

#include <Windows.h>
#include <wincontypes.h>

class FallingLetter
{
public:

private:
	char character;
	COORD position;
	
public:
	void Update();
	void Draw();

private:
};

