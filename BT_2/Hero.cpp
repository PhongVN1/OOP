#include"Hero.h"
Hero::Hero()
{
	x = 0;
	y = 0;
}

Hero::~Hero()
{
}

void Hero::moveUp()
{
	if (y == 0) {}
	else
		y = y - 1;
}

void Hero::moveDown()
{
	y = y + 1;
}

void Hero::moveLeft()
{
	if (x == 0) {}
	else
		x = x - 1;
}

void Hero::moveRight()
{
	x = x + 1;
}

void Hero::input()
{
	cout << "Nhap ten Hero: ";
	getline(cin, name);
}
