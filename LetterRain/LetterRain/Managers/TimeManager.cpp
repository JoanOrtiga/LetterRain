#include "TimeManager.h"

#include <ctime>
#include <iostream>

TimeManager::TimeManager()
{
}

long TimeManager::GetElapsedTime() const
{
	return elapsedTime;
}

bool TimeManager::ShouldExecuteNextFrame()
{
	bool shouldExecuteNextFrame = false;
	clock_t timeBetweenFrames = clock() - lastFrameTime;
	if (timeBetweenFrames >= perFrameCycles)
	{
		shouldExecuteNextFrame = true;
		elapsedTime = lastFrameTime / CLOCKS_PER_SEC;
		lastFrameTime = clock();
	}
	return shouldExecuteNextFrame;
}
