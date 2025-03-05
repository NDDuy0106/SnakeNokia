#include<iostream>
#include<conio.h>
#include<ctime>
#include<thread>
#include<chrono>
#include<future>
#include"MyLibrary.h"
#define max 100

using namespace std;

int toa_do_x[max] = { 0 };	//Tọa độ x của rắn
int toa_do_y[max] = { 0 };	//Tọa độ y của rắn
int dot_ran = 8;	//Số đốt của rắn lúc đầu
int xqua = -1;		//Tạo tọa độ x cho quả
int yqua = -1;		//Tạo tọa độ y cho quả
int point = 0;		//Điểm
int x_to = -1;		//Tạo tọa độ x cho quả to
int y_to = -1;		//Tạo tọa độ y cho quả to
int dem = 0;		//Đủ số đếm sẽ tạo quả to
int tgian = 200;	//Tgian duy trì quả to
//===============================
void play();
void ve_tuong();
void khoi_tao_ran();
void ve_ran();
void di_chuyen_ran(int x, int y);
bool check_ran_cham_than();
bool check_ran_cham_tuong();
void tao_qua();
void ve_qua();
bool check_an_qua();
bool check_ran_de_qua();
void ran_an_qua();
bool check_qua_to_voi_ran(int x_to, int y_to);
bool check_qua_to_voi_nho(int x_to, int y_to);
void tao_qua_to();
void ve_qua_to();
void xoa_qua_to();
bool check_an_qua_to();
void ran_an_qua_to();
void speed();
//===============================
void main()
{
	gotoXY(46, 0);
	cout << "Snake Nokia";
	gotoXY(98, 10);
	cout << "Total Points:   ";
	gotoXY(113, 10);
	cout << point;
	play();
	//Xóa những dòng code thừa:
	cin.get();
	system("cls");
}

void play()
{
	srand(time(0));
	ShowCur(0);
	doi_mau(10);
	ve_tuong();
	khoi_tao_ran();
	tao_qua();
	while (check_ran_de_qua())
	{
		tao_qua();
	}
	ve_qua();
	int check = 3;	//0: đi lên
					//1: đi xuống
					//2: đi trái
					//3: đi phải
	int x = toa_do_x[0];	//vị trí ban đầu của x
	int y = toa_do_y[0];	//vị trí ban đầu của y
	while (1)
	{
		//-----xóa dữ liệu cũ-----
		gotoXY(toa_do_x[dot_ran], toa_do_y[dot_ran]);
		cout << " ";
		//-----in rắn-----
		ve_ran();
		//-----điều khiển-----
		if (_kbhit())		//kiểm tra xem bàn phím có đang nhấn nút nào hay không?
		{
			char key = _getch();
			if (key == -32 || key == 224)	//nhấn phím đặc biệt (F0 -> F12, mũi tên, ...)
			{
				key = _getch();
				if (key == 72 && check != 1)		//đi lên
				{
					check = 0;
				}
				else if (key == 80 && check != 0)	//đi xuống
				{
					check = 1;
				}
				else if (key == 75 && check != 3)	//đi trái
				{
					check = 2;
				}
				else if (key == 77 && check != 2)	//đi phải
				{
					check = 3;
				}
			}
		}
		//-----di chuyển-----
		if (check == 0)
		{
			y--;
		}
		else if (check == 1)
		{
			y++;
		}
		else if (check == 2)
		{
			x--;
		}
		else if (check == 3)
		{
			x++;
		}
		//-----xử lí rắn-----
		ran_an_qua();
		ran_an_qua_to();
		di_chuyen_ran(x, y);
		if (dem >= 5)
		{
			tao_qua_to();
			ve_qua_to();
			dem = 0;
		}
		//-----gameover-----
		if (check_ran_cham_tuong() || check_ran_cham_than())
		{
			system("cls");
			gotoXY(46, 10);
			cout << "G A M E O V E R" << endl;
			gotoXY(42, 13);
			cout << "Press Enter x2 to exit!";
			gotoXY(45, 16);
			cout << "Total Points: " << point;
			break;
		}
		//-----speed-----
		speed();
	}
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

void di_chuyen_ran(int x, int y) //di chuyển con rắn
{
	for (int i = dot_ran; i > 0; i--)
	{
		toa_do_x[i] = toa_do_x[i - 1];
		toa_do_y[i] = toa_do_y[i - 1];
	}
	toa_do_x[0] = x;
	toa_do_y[0] = y;
}

bool check_ran_cham_than()
{
	for (int i = 1; i < dot_ran; i++)
	{
		if (toa_do_x[0] == toa_do_x[i] && toa_do_y[0] == toa_do_y[i])
			return true;
	}
	return false;
}

bool check_ran_cham_tuong()
{
	if (toa_do_x[0] == 10 || toa_do_x[0] == 95 || toa_do_y[0] == 1 || toa_do_y[0] == 25)
	{
		return true;
	}
	return false;
	return false;
}

void tao_qua()
{
	do
	{
		xqua = rand() % (94 - 11 + 1) + 11;
		yqua = rand() % (24 - 2 + 1) + 2;
	} while (check_ran_de_qua());
	
}

void ve_qua()
{
	gotoXY(xqua, yqua);
	doi_mau(12);
	cout << "$";
	doi_mau(10);
}

bool check_an_qua()
{
	if (toa_do_x[0] == xqua && toa_do_y[0] == yqua)
	{
		return true;
	}
	return false;
}

bool check_ran_de_qua()		//kiểm tra quả có sinh ra ở vị trí đốt của rắn không
{
	for (int i = 0; i < dot_ran; i++)
	{
		if (xqua == toa_do_x[i] && yqua == toa_do_y[i])
			return true;
	}
	return false;
}

void ran_an_qua()
{
	if (check_an_qua())
	{
		dot_ran++;		//tăng đốt rắn
		tao_qua();		//tạo quả mới
		ve_qua();		//vẽ quả mới
		point += 100;	//tăng điểm
		gotoXY(113, 10);
		cout << point;
		dem++;
	}
}

bool check_qua_to_voi_ran(int x_to, int y_to)		//kiểm tra xem quả to có trùng với tọa độ rắn không
{
	for (int i = 0; i < dot_ran; i++)
	{
		int sx = toa_do_x[i];
		int sy = toa_do_y[i];
		if (sx >= x_to && sx <= x_to + 2 && sy >= y_to && sy <= y_to + 2)
		{
			return true;
			break;
		}
	}
	return false;
}

bool check_qua_to_voi_nho(int x_to, int y_to)		//kiểm tra xem quả to có trùng với quả nhỏ không
{
	if (xqua >= x_to && xqua <= x_to + 2 && yqua >= y_to && yqua <= y_to + 2)
	{
		return true;
	}
	return false;
}

void tao_qua_to()
{
	do
	{
		x_to = rand() % (92 - 11 + 1) + 11;
		y_to = rand() % (22 - 2 + 1) + 2;
	} while (check_qua_to_voi_ran(x_to, y_to) || check_qua_to_voi_nho(x_to, y_to));
}

void ve_qua_to()
{
	gotoXY(x_to, y_to);
	doi_mau(12);
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			cout << "$";
		}
		gotoXY(x_to, y_to + x + 1);
	}
	doi_mau(10);
}

void xoa_qua_to()
{
	gotoXY(x_to, y_to);
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			cout << " ";
		}
		gotoXY(x_to, y_to + x + 1);
	}
}

bool check_an_qua_to()
{
	if (toa_do_x[0] >= x_to && toa_do_x[0] <= x_to + 2 && toa_do_y[0] >= y_to && toa_do_y[0] <= y_to + 2 && x_to != -1 && y_to != -1)
	{
		return true;
	}
	return false;
}

void ran_an_qua_to()
{
	if (check_an_qua_to())
	{
		point += 350;
		gotoXY(113, 10);
		cout << point;
		xoa_qua_to();
		x_to = -1;
		y_to = -1;
	}
}

void speed()
{
	if (point >= 0 && point <= 1000)
		Sleep(100);
	else if (point > 1000 && point <= 2500)
		Sleep(90);
	else if (point > 2500 && point <= 5000)
		Sleep(80);
	else if (point > 5000 && point <= 7000)
		Sleep(60);
	else if (point > 7000 && point <= 10000)
		Sleep(50);
	else
		Sleep(25);
}