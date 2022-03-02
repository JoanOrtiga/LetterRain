#include "RandomGeneratorManager.h"

#include <cstdlib>
#include <ctime>

#define ALPHABET_LENGTH 26
char RandomGeneratorManager::letters[] = "QWERTYUIOPASDFGHJKLZXCVBNM";

void RandomGeneratorManager::Init()
{
	srand(time(NULL));
}

int RandomGeneratorManager::GetRandomNumber()
{
	return rand();
}

int RandomGeneratorManager::GetRandomNumberInRange(int min, int max)
{
	return min + (rand() % max);
}

char RandomGeneratorManager::GetRandomLetter()
{
	return letters[rand() % ALPHABET_LENGTH];
}

void RandomGeneratorManager::SetSeed(int seed)
{
	srand(seed);
}

