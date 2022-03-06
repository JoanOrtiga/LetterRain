#pragma once

#include <time.h>

class TimeManager
{
public:
	int elapsedTime = 0;

private:
	clock_t lastFrameTime = clock();
	int perFrameCycles = 400;//400;

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

