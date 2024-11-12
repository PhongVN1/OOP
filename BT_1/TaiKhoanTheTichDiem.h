#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"TaiKhoanTheTinDung.h"
using namespace std;
class TaiKhoanTheTichDiem : public TaiKhoanTheTinDung
{
private:
	double rewardRate;
	unsigned int currentPoints;

public:
	TaiKhoanTheTichDiem();
	~TaiKhoanTheTichDiem();

	int getCurrentPoints();
	bool charge(double amount);
	void payWithPoints(int pAmount);
	
	void Nhap();
	void Xuat();
};

