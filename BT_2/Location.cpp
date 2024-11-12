#include"Location.h"

Location::Location()
{
}

Location::~Location()
{
}

void Location::setLocation(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Location::getX()
{
	return x;
}

int Location::getY()
{
	return y;
}
