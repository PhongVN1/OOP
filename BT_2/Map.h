#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <Windows.h>//dung cho ham Sleep
#include"Hero.h"
#include"Monster.h"
#include"Warrior.h"
#include"Construction.h"

class Map
{
public:

	//tao map
	void createMap();
	void createContruction();
	void createMonster();
	void createWarrior();

	//thuc hien tro choi
	void draw();
	void drawMap();
	void move();
	void over();

	//Tran chien dien ra
	void battle(vector<Warrior*>&,Monster*);

	//
	
	~Map();
private:
	int Y;//hang`
	int X;//cot
	Hero hero;
	vector<Monster*> monster_list;
	vector<Warrior*> warrior_list;
	vector<Construction*> construction_list;

	// tao map la doi tuong duy nhat
private:
	static Map* instance;
	Map() {};
public:
	static Map* GetInstance()
	{
		if (instance == NULL)
		{
			instance = new Map();
		}
		return instance;
	}
	static void DeleteInstance() 
	{
		if (instance)
		{
			delete instance;
			instance = NULL;
		}
	}
};
