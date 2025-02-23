#pragma once //Giup khong bi xung dot thu vien
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