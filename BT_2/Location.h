#pragma once
#include<iostream>
class Location
{
public:
	Location();
	~Location();

	void setLocation(int x, int y);
	int getX();
	int getY();

	virtual void input() = 0;

protected:
	int x;
	int y;
};
