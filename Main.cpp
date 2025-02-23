#include<iostream>
#include"MyLibrary.h"
#define max 100

using namespace std;

int toa_do_x[max] = { 0 };
int toa_do_y[max] = { 0 };
int dot_ran = 4;   //Số đốt của rắn lúc đầu

void play();
void ve_tuong();
void khoi_tao_ran();
void ve_ran();
//===============================
void main()
{
	cout << "Press Enter to Exit ! \n";
	play();
	//Xóa những dòng code thừa:
	cin.get();
	system("cls");
}

void play()
{
	doi_mau(12);
	ve_tuong();
	khoi_tao_ran();
	ve_ran();
}

void ve_tuong() //vẽ tường trong game
{
	for (int i = 10; i <= 95; i++)
	{
		gotoXY(i, 1);
		cout << char(196);
		gotoXY(i, 25);
		cout << char(196);
	}
	for (int y = 1; y <= 25; y++)
	{
		gotoXY(10, y);
		cout << char(179);
		gotoXY(95, y);
		cout << char(179);
	}
}

void khoi_tao_ran()
{
	//Chọn tọa độ cho đầu rắn
	int x_ban_dau = 50;     
	int y_ban_dau = 13;
	//Tạo mấy cái đốt sau
	for (int i = 0; i < dot_ran; i++)
	{
		toa_do_x[i] = x_ban_dau--;
		toa_do_y[i] = y_ban_dau;
	}
}

void ve_ran()
{
	for (int i = 0; i < dot_ran; i++)
	{
		gotoXY(toa_do_x[i], toa_do_y[i]);
		if (i == 0)
			cout << "0";
		else
			cout << "o";
	}
}