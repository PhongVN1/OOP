#include"Construction.h"

Construction::Construction()
{
}

Construction::Construction(int x, int y)
{
	this->x = x;
	this->y = y;
}

Construction::~Construction()
{
}

string Construction::getName()
{
	return name;
}

void Construction::setName(string n)
{
	name = n;
}
void Construction::input()
{
	cout << "Nhap ten cong trinh: ";
	getline(cin, name);
}
