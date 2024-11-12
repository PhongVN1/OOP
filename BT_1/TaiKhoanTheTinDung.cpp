#include"TaiKhoanTheTinDung.h"
TaiKhoanTheTinDung::TaiKhoanTheTinDung()
{
}

TaiKhoanTheTinDung::~TaiKhoanTheTinDung()
{
}

double TaiKhoanTheTinDung::getBalance()
{
	return this->So_du;
}

bool TaiKhoanTheTinDung::charge(double amount)
{
	if (So_du + amount <= Han_muc_tin_dung)
	{
		string temp;
		So_du = So_du + amount;
		cout << "Nhap ngay hien tai(dd/MM/yyyy): ";
		getline(cin, temp);
		LichSuGiaoDich ls(So_tai_khoan, amount, "Thanh toan tien", temp);
		Lich_su.push_back(ls);
		return true;
	}
	else
		return false;
}

void TaiKhoanTheTinDung::payment(double amount)
{
	So_du = So_du - amount;
}

void TaiKhoanTheTinDung::showHistory()
{
	for (int i = 0; i < Lich_su.size(); i++)
	{
		Lich_su[i].Xuat();
	}
}

void TaiKhoanTheTinDung::Nhap()
{
	cout << "Nhap so tai khoan: ";
	getline(cin, So_tai_khoan);

	cout << "Nhap so du: ";
	cin >> So_du;
	cin.ignore();

	cout << "Nhap ngay phat hanh(dd/MM/yyyy): ";
	getline(cin, Ngay_phat_hanh);

	//cout << "Nhap lai suat: ";
	//cin >> Lai_suat;
	//cin.ignore();

	//cout << "Nhap Thanh_toan_toi_thieu: ";
	//cin >> Lai_suat;
	//cin.ignore();

	//cout << "Nhap Phi_tra_cham: ";
	//cin >> Phi_tra_cham;
	//cin.ignore();

}

void TaiKhoanTheTinDung::Xuat()
{
	cout << "So tai khoan: " << So_tai_khoan<<endl;

	cout << "So du: " << So_du<<endl;

	cout << "Ngay phat hanh(dd/MM/yyyy): " << Ngay_phat_hanh<<endl;
}
