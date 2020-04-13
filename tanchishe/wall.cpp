#include <iostream>
#include "wall.h"

using namespace std;

void Wall::initwall()
{
	int i,j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			if(j == 0 || i == 0 || j == col -1 || i == row - 1)
			{
				WallArray[i][j] = '*';
			}
			else
			{
				WallArray[i][j] = ' ';
			}
		}
	}
}

void Wall::drawwall()
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cout<<WallArray[i][j]<<" ";
		}
		if(i == 5)
		{
			cout<<"版本：1.0";
		}
		if(i == 6)
		{
			cout<<"制作人：张志伟";
		}
		if(i == 7)
		{
			cout<<"w：向上";
		}
		if(i == 8)
		{
			cout<<"s：向下";
		}
		if(i == 9)
		{
			cout<<"a：向左";
		}
		if(i == 10)
		{
			cout<<"w：向右";
		}
		cout<<endl;
	}
}

void Wall::setwall(int x,int y,char c)
{
	WallArray[x][y] = c;
}

char Wall::getwall(int x, int y)
{
	return WallArray[x][y];
}
