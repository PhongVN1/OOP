#pragma once
#include<iostream>
#include<string>
using namespace std;
class LichSuGiaoDich
{
private:
	string So_tai_khoan;
	double So_tien_chuyen_khoan;
	string Noi_dung_chuyen_khoan;
	string Ngay_giao_dich;

public:
	LichSuGiaoDich();
	LichSuGiaoDich(string, double, string, string);
	~LichSuGiaoDich();

	void Nhap();
	void Xuat();

};
