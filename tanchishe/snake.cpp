#include<windows.h>
#include"snake.h"


using namespace std;

HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量

void gotoxy1(HANDLE hOut1, int x, int y)
{
	COORD pos = {x, y};

	SetConsoleCursorPosition(hOut1, pos);
}

snake::snake(Wall &tempwall, FOOD &tempfood):wall(tempwall),food(tempfood)
{
	pHead = NULL;
	isRool = false;
}

void snake::destorypoint()
{
	Point *nextpoint;
	while(pHead != NULL)
	{
		nextpoint = pHead->next;
		delete pHead;
		pHead = nextpoint;
	}
}

void snake::addsnake(int x,int y)
{
	Point *newpoint = new Point;
	newpoint->x = x;
	newpoint->y = y;
	newpoint->next = NULL;
	if(pHead != NULL)
	{
		wall.setwall(pHead->x, pHead->y, '=');
		gotoxy1(hOut1,  pHead->y * 2, pHead->x);
		cout<<"=";
	}
	newpoint->next = pHead;
	pHead = newpoint;
	wall.setwall(newpoint->x, newpoint->y, '@');
	gotoxy1(hOut1, newpoint->y * 2, newpoint->x);
	cout<<"@";
}

void snake::Initsnake()
{
	destorypoint();
	addsnake(5,3);
	addsnake(5,4);
	addsnake(5,5);
}

void snake::delpoint()
{
	if(pHead == NULL || pHead->next == NULL)
	{
		return;
	}
	Point *Pur = pHead->next;
	Point *Pre = pHead;
	while(Pur->next != NULL)
	{
		Pur = Pur->next;
		Pre = Pre->next;
	}
	wall.setwall(Pur->x, Pur->y, ' ');
	gotoxy1(hOut1, Pur->y * 2, Pur->x);
	cout<<" ";
	delete Pur;
	Pur = NULL;
	Pre->next = NULL;
}

bool snake::move(char key)
{
	int x = pHead->x;
	int y = pHead->y;
	switch(key)
	{
		case RIGHT:
			y++;
			break;
		case LEFT:
			y--;
			break;
		case UP:
			x--;
			break;
		case DOWN:
			x++;
			break;
		default:
			break;
	}

	Point *Pur = pHead->next;
	Point *Pre = pHead;
	while(Pur->next != NULL)
	{
		Pur = Pur->next;
		Pre = Pre->next;
	}

	if(Pur->x == x && Pur->y == y)
	{
		isRool = true;
	}

	if(wall.getwall(x,y) == '*' || wall.getwall(x,y) == '=')
	{
		addsnake(x,y);
		delpoint();
		system("cls");
		wall.drawwall();
		cout << "得分：" << getScore() << "分" << endl;
		cout << "GAME OVER" << endl;
		return false;
	}else
	{
		if(wall.getwall(x,y) == '#')
		{
			addsnake(x,y);
			food.setfood();
		}else{
			addsnake(x,y);
			delpoint();
			if (isRool == true)
			{
				wall.setwall(x, y, '@');
				gotoxy1(hOut1,y * 2, x);
				cout << "@";
			}
		}
		return true;
	}

}

int snake::countList()
{
	int count = 0;
	Point *Pur = pHead;
	while(Pur != NULL)
	{
		count++;
		Pur = Pur->next;
	}
	return count;
}

int snake::getSleepTime()
{
	int count = countList();
	int sleeptime = 0;
	if(count <= 5)
	{
		sleeptime = 300;
	}else if(count <= 10)
	{
		sleeptime = 200;
	}else{
		sleeptime = 100;
	}
	return sleeptime;
}

int snake::getScore()
{
	int count = countList();
	int score = 0;
	score = (count-3)*100;
	return score;
}
