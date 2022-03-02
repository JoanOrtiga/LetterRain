#pragma once

#include <time.h>

class TimeManager
{
public:
	static TimeManager instance;
	int elapsedTime = clock();

private:
	clock_t lastFrameTime = clock();
	int perFrameCycles = 270;

public:
	TimeManager();
	clock_t GetElapsedTime() const;
	bool ShouldExecuteNextFrame();
	~TimeManager();
};

