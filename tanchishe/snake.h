#ifndef SNAKE_H
#define SNAKE_H

#include<iostream>
#include"food.h"
#include"wall.h"
using namespace std;

class snake
{
public:
	snake(Wall &tempwall, FOOD &tempfood);
	enum{
		UP = 'w',
		DOWN = 's',
		RIGHT = 'd',
		LEFT = 'a'
	};
	struct Point{
		int x;
		int y;
		Point *next;
	};
	void Initsnake();
	void destorypoint();
	void addsnake(int x, int y);
	void delpoint();
	//移动操作
	//返回值代表是否成功
	bool move(char key);
	//设定难度
	//获取刷屏时间
	int getSleepTime();
	//获取蛇的身段
	int countList();
	//获取分数
	int getScore();
	Point * pHead;

	Wall &wall;

	FOOD &food;

	bool isRool;//循环的标识
	
	
};

#endif
