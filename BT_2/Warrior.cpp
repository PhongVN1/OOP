#include"Warrior.h"
Warrior::Warrior()
{
	level = 1;
}

Warrior::Warrior(int x, int y)
{
	this->x = x;
	this->y = y;
	level = 1;
}

Warrior::~Warrior()
{
}

int Warrior::getHP()
{
	return HP;
}

int Warrior::getDF()
{
	return DF;
}

int Warrior::getATK()
{
	return ATK;
}

int Warrior::getlevel()
{
	return level;
}

string Warrior::getName()
{
	return name;
}

int Warrior::takeDamage()
{
	return HP + DF;
}

void Warrior::setHP(int hp)
{
	HP = hp;
}

void Warrior::setDF(int df)
{
	DF = df;
}

void Warrior::setATK(int atk)
{
	ATK = atk;
}

void Warrior::levelUp()
{
	level = level + 1;
	ATK = ATK + 1;
	DF = DF + 5;
}

void Warrior::input()
{
	cout << "Nhap thong tin chien binh\n";
	cout << "Nhap ten: ";
	getline(cin, name);
	cout << "Nhap mau: ";
	cin >> HP;
	cin.ignore();
	cout << "Nhap tan cong: ";
	cin >> ATK;
	cin.ignore();
	cout << "Nhap giap: ";
	cin >> DF;
	cin.ignore();
}