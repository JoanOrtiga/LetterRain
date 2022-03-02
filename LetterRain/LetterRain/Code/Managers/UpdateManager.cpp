#include "UpdateManager.h"

UpdateManager::UpdateManager(FallingLettersController* _fallingLettersController, TimeManager* _timeManager) : fallingLettersController(_fallingLettersController), timeManager(_timeManager) 
{
}

void UpdateManager::Update()
{
	fallingLettersController->Update();
}
