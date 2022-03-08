#include "Settings.h"

#include "ConsoleController.h"
int Settings::GetLoseRow()
{
	return ConsoleController::consoleSizeY - endGameRow;
}

int Settings::GetTimeBetweenSpawnsByTime(long time)
{
	int spawnTime = timeBetweenSpawns[TIME_BETWEEN_SPAWNS_NUMBER-1][1];
	for(int i = 0; i < TIME_BETWEEN_SPAWNS_NUMBER; ++i)
	{
		if(time < timeBetweenSpawns[i][0])
		{
			spawnTime = timeBetweenSpawns[i][1];
			break;
		}
	}

	return spawnTime;
}
