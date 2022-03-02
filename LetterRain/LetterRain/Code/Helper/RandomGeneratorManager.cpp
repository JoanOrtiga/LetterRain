#include "RandomGeneratorManager.h"

#include <cstdlib>
#include <ctime>

#define ALPHABET_LENGTH 26
char RandomGeneratorManager::letters[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

void RandomGeneratorManager::Init()
{
	srand(time(NULL));
}

char RandomGeneratorManager::GetRandomLetter()
{
	return letters[rand() % ALPHABET_LENGTH];
}

void RandomGeneratorManager::SetSeed(int seed)
{
	srand(seed);
}

