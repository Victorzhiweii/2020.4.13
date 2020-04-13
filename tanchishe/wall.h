#ifndef WALL_H
#define WALL_H

#include<iostream>
using namespace std;

class Wall
{
public:
	enum
	{
		row = 20,
		col = 20
	};
	void initwall();
	void drawwall();
	void setwall(int x, int y, char c);
	char getwall(int x, int y);
private:
	char WallArray[row][col];
};

#endif
