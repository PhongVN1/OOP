#pragma once
#include <iostream>
#include <string>

#include"Location.h"
using namespace std;

class Monster :public Location
{
public:
	Monster();
	Monster(int, int);
	~Monster();

	int getHP();
	int getFury();
	int getATK();
	int getlevel();

	string getName();

	void setHP(int);
	void setFury(int);
	void setATK(int);

	void levelUp();

	int Attack();

	void input();

private:
	int HP;
	int ATK;
	int level;
	int fury=1;
	string name;
};
