#ifndef FOOD_H
#define FOOD_H

#include<iostream>
using namespace std;
#include"wall.h"

class FOOD
{
public:
	FOOD(Wall &tempwall);
	void setfood();

	int foodx;
	int foody;

	Wall &wall;
};

#endif
