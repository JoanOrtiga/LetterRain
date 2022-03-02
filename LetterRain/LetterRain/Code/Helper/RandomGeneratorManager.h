#pragma once
class RandomGeneratorManager
{
private:
	static char letters[];


public:
	RandomGeneratorManager() = delete;

	static char GetRandomLetter();
	static void SetSeed(int seed);
	static void Init();

private:
	
};

