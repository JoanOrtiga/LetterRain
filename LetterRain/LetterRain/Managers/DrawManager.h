#pragma once


class DrawManager
{
public:

private:
	const char cornerTopLeft = 201;		//╔
	const char flatHorizontal = 205;	//═
	const char cornerTopRight = 187;	//╗
	const char flatVertical = 186;		//║

	const char verticalWithLeft = 185;	//╣
	const char verticalWithRight = 204;	//╠

public:
	DrawManager();
	void Draw();

private:
	void DrawPlayField();
	void Fill(char character, int fill);

	void UpdateConsole();

};

