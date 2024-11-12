#pragma once
#include<iostream>
#include<string>

#include"Location.h"
using namespace std;
class Hero : public Location
{
public:
	Hero();
	~Hero();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void input();

private:
	string name;
};
