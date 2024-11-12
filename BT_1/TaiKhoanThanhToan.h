#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"LichSuGiaoDich.h"
using namespace std;

class TaiKhoanThanhToan
{
protected:
	string So_tai_khoan;
	double So_du;
	string Ngay_phat_hanh;
	vector<LichSuGiaoDich> Lich_su;

public:
	TaiKhoanThanhToan();
	~TaiKhoanThanhToan();
	double getBalance();
	bool transferTo(double amount);
	void showHistory();
	void Nhap();
	void Xuat();
};
