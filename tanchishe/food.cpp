#include<iostream>
#include<windows.h>
#include"food.h"
#include"wall.h"    

using namespace std;

HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量

void gotoxy(HANDLE hOut2, int x, int y)
{
	COORD pos = {x, y};

	SetConsoleCursorPosition(hOut2, pos);
}

FOOD::FOOD(Wall& tempwall):wall(tempwall)
{

}

void FOOD::setfood()
{
	while(1)
	{
		foodx = rand() % (Wall::row - 2) + 1;
		foody = rand() % (Wall::col - 2) + 1;
		if(wall.getwall(foodx, foody) == ' ')
		{
			wall.setwall(foodx, foody, '#');
			gotoxy(hOut2, foody * 2,  foodx);
			cout<<'#';
			break;
		}
	}
}
