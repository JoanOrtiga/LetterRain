#include <iostream>

#include "ConsoleController.h"
#include "Game.h"
#include "Helper/RandomGeneratorManager.h"

#define SEED 0

int main()
{
    RandomGeneratorManager::Init();

#if (SEED != 0)
    RandomGeneratorManager::SetSeed(SEED);
    std::cout << SEED;
#endif

    Game::GetInstance().Init();
	Game::GetInstance().Loop();
}
