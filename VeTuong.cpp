#include<iostream>

using namespace std;

void ve_tuong1() //vẽ tường trong game
{
	for (int y = 1; y <= 25; y++)   //Trục Oy sẽ kéo dài từ điểm 1 -> 25
	{
		for (int x = 10; x <= 95; x++)   //Trục Ox sẽ kéo dài từ điểm 10 -> 95
		{
			if (y == 1 || y == 25)
			{
				cout << char(196);
			}
			else
			{
				if (x == 10 || x == 95)
				{
					cout << char(179);
				}
				else
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}
}
