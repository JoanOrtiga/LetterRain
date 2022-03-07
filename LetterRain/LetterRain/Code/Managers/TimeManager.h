#pragma once

#include <time.h>
#include "../Settings.h"

class TimeManager
{
public:
	int elapsedTime = 0;

private:
	clock_t lastFrameTime = clock();
	int perFrameCycles = Settings::cyclesPerFrame;

public:
	static TimeManager& GetInstance()
	{
		static TimeManager instance;
		return instance;
	}

	TimeManager(){}
	clock_t GetElapsedTime() const;
	bool ShouldExecuteNextFrame();
	~TimeManager();
};

