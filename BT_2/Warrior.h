#pragma once
#include <iostream>
#include <string>
#include"Location.h"

using namespace std;
class Warrior :public Location
{
public:
	Warrior();
	Warrior(int, int);
	~Warrior();

	int getHP();
	int getDF();
	int getATK();
	int getlevel();

	string getName();

	int takeDamage();

	void setHP(int);
	void setDF(int);
	void setATK(int);

	void levelUp();

	void input();

private:

	int HP;
	int DF;
	int ATK;
	int level;
	string name;

};

