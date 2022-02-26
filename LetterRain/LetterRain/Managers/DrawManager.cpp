#include "DrawManager.h"

#include <iostream>
#include <io.h>
#include <fcntl.h>


DrawManager::DrawManager()
{
}

void DrawManager::Draw()
{
	DrawPlayField();
}

void DrawManager::DrawPlayField()
{
	_setmode(_fileno(stdout), _O_U8TEXT);
	//system("cls");
	char32_t topLeftCorner = '\x2554';

	

	wprintf(L"\x2554");
	//Fill('═', 92);
	//std::cout << '╗';
}

void DrawManager::Fill(char character, int fillAmount)
{
	std::cout.width(fillAmount);
	std::cout.fill(character);
	std::cout.width(0);
}