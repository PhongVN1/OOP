#include"Monster.h"

Monster::Monster()
{
	level = 1;
}
Monster::Monster(int x, int y)
{
	this->x = x;
	this->y = y;
	level = 1;
}

Monster::~Monster()
{

}

int Monster::getHP()
{
	return HP;
}

int Monster::getFury()
{
	return fury;
}

int Monster::getATK()
{
	return ATK;
}

int Monster::getlevel()
{
	return level;
}

string Monster::getName()
{
	return name;
}
void Monster::setHP(int hp)
{
	HP = hp;
}

void Monster::setFury(int f)
{
	fury = f;
}

void Monster::setATK(int atk)
{
	ATK = atk;
}

void Monster::levelUp()
{
	level = level + 1;
	fury = fury + 3;
}

int Monster::Attack()
{
	return ATK + (fury * 2);
}

inline void Monster::input()
{
	cout << "Nhap thong tin cua quai vat\n";
	cout << "Nhap ten: ";
	getline(cin, name);
	cout << "Nhap mau: ";
	cin >> HP;
	cin.ignore();
	cout << "Nhap tan cong: ";
	cin >> ATK;
	cin.ignore();
}
