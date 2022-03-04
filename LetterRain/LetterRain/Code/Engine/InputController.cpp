#include "InputController.h"

#include <windows.h>


bool InputController::IsKeyPressed(char character)
{
	return GetKeyState(character) & 0x8000;
}
