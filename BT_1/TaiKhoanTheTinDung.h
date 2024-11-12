#pragma once
#include <iostream>
#include <string>
#include"TaiKhoanThanhToan.h"
class TaiKhoanTheTinDung : public TaiKhoanThanhToan
{
protected:
	double Han_muc_tin_dung = 30000000;
	double Lai_suat;
	double Thanh_toan_toi_thieu;
	double Phi_tra_cham;
	//double So_du_hien_tai;


public:
	TaiKhoanTheTinDung();
	~TaiKhoanTheTinDung();

	double getBalance();
	bool charge(double amount);
	void payment(double amount);
	void showHistory();

	void Nhap();
	void Xuat();
};


