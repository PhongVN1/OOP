#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"TaiKhoanTheTinDung.h"
using namespace std;
class TaiKhoanTheHoanTien : public TaiKhoanTheTinDung
{
private:
	double cashbackRate;
	double currentCashBack;


public:
	TaiKhoanTheHoanTien();
	~TaiKhoanTheHoanTien();

	int getCurrentCashBack();
	bool charge(double amount);
	void redeemCashBack();
	
	void Nhap();
	void Xuat();	
};