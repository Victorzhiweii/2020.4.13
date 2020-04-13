#include<iostream>
#include "snake.h"

using namespace std;

#include<ctime>
#include<conio.h>
#include<Windows.h>
//新加了一个可以重复进行游戏的功能
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy3(HANDLE hOut, int x, int y)
{
	COORD pos = {x , y};
	SetConsoleCursorPosition(hOut, pos);
}

int main()
{
	srand(time(NULL));

		//是否死亡的标识
	bool isDead = false;

	char preKey = NULL;
	Wall wall;
	

	FOOD food(wall);
	

	snake snake(wall,food);
	char key;
	while(1)
	{	
		wall.initwall();
		wall.drawwall();
		food.setfood();
		snake.Initsnake();
		gotoxy3(hOut, 0, Wall::row);
		cout << "得分：" << snake.getScore() << "分" << endl;
		while(!isDead)
		{
			key = _getch();
			//判断如果是第一次按了，左键，才不能激活游戏
			//判断上一次移动方向
			if (preKey == NULL && key == snake.LEFT)
			{
				continue;
			}

			do
			{
				if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
				{
					//判断本次按键是否与上次冲突
					if ((key == snake.LEFT&&preKey == snake.RIGHT )||
						(key == snake.RIGHT&&preKey == snake.LEFT )||
						(key == snake.UP&&preKey == snake.DOWN) ||
						(key == snake.DOWN&&preKey == snake.UP) 
						)
					{
						key = preKey;
					}
					else
					{
						preKey = key;//不是冲突按键，可以更新按键
					}
					
					if (snake.move(key) == true)
					{
						//移动成功
						//system("cls");
						//wall.drawWall();
						gotoxy3(hOut, 0, Wall::row);
		
						cout << "得分：" << snake.getScore() << "分" << endl;
						Sleep(snake.getSleepTime());
					}
					else
					{
						isDead = true;
						break;
					}
				}
				else
				{
					key = preKey;//强制将错误按键变为上一次移动的方向
				}
			
			} while (!_kbhit());//当没有键盘输入的时候返回0
		}
		cout << "是否继续游戏（Y/N）：";
		for(;;)
		{
			key = _getch();
			if(key == 'y' || key == 'Y')
			{
				isDead = false;
				gotoxy3(hOut, 0, 0);
				break;
			}else if (key == 'n' || key == 'N'){
				system("pause");
				return 0;
			}else{

			}
		}
		
	}
	system("pause");
	return 0;
}
