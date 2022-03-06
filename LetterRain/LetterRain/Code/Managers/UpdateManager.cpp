#include "UpdateManager.h"

UpdateManager::UpdateManager(FallingLettersController* _fallingLettersController) : fallingLettersController(_fallingLettersController)
{
}

UpdateManager::~UpdateManager()
{

}

void UpdateManager::Update()
{
	fallingLettersController->Update();
}

void UpdateManager::DrawnUpdate()
{
	fallingLettersController->DrawnUpdate();
}
