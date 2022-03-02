#pragma once
class RandomGeneratorManager
{
private:
	static char letters[];


public:
	RandomGeneratorManager() = delete;

	static int GetRandomNumberInRange(int min, int max);
	static char GetRandomLetter();
	static void SetSeed(int seed);
	static void Init();
	static int GetRandomNumber();

private:
	
};

