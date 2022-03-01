#pragma once

#include <vector>
#include "FallingLetter.h"

class FallingLettersController
{
public:
	
private:
	std::vector<FallingLetter>* fallingLetters;
	
public:
	FallingLettersController();
	void Update();
	void Draw();

private:

};

