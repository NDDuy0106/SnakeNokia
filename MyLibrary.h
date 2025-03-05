#pragma once //Giúp không bị xung đột thư viện
#include<iostream>
#include<Windows.h>

using namespace std;

void doi_mau(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoXY(int x, int y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { SHORT(x), SHORT(y) });
}

void ShowCur(bool CursorVisibility)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorINFO;
	GetConsoleCursorInfo(hConsole, &cursorINFO);
	cursorINFO.bVisible = CursorVisibility;	//true: hiện con trỏ
											//false: ẩn con trỏ
	SetConsoleCursorInfo(hConsole, &cursorINFO);
}