#pragma once
#include<iostream>
#include<string>
#include"Location.h"
using namespace std;
class Construction : public Location
{
public:
	Construction();
	Construction(int,int);
	~Construction();

	string getName();
	void setName(string);

	void input();
	
private:
	string name;
};
