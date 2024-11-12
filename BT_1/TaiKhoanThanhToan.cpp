#include"TaiKhoanThanhToan.h"

TaiKhoanThanhToan::TaiKhoanThanhToan()
{
	So_tai_khoan = "#";
	So_du = 1;
	Ngay_phat_hanh = "1/1/2020";
}

TaiKhoanThanhToan::~TaiKhoanThanhToan()
{
}

double TaiKhoanThanhToan::getBalance()
{
	return this->So_du;
}

bool TaiKhoanThanhToan::transferTo(double amount)
{
	if (So_du >= amount)
	{
		string temp;

		So_du = So_du - amount;

		cout << "Nhap ngay hien tai(dd/MM/yyyy): " ;
		getline(cin, temp);
		LichSuGiaoDich ls(So_tai_khoan,amount,"Chuyen khoan ngan hang", temp);
		Lich_su.push_back(ls);

		return true;
	}
	else
		return false;
}

void TaiKhoanThanhToan::showHistory()
{
	for (int i = 0; i < Lich_su.size(); i++)
	{
		Lich_su[i].Xuat();
	}
}

void TaiKhoanThanhToan::Nhap()
{
	cout << "Nhap so tai khoan: ";
	getline(cin,So_tai_khoan);	

	cout << "Nhap so du: ";
	cin>>So_du;
	cin.ignore();

	cout << "Nhap ngay phat hanh(dd/MM/yyyy): ";
	getline(cin, Ngay_phat_hanh);
	
}

void TaiKhoanThanhToan::Xuat()
{
	cout << "So tai khoan: " << So_tai_khoan << endl;

	cout << "So du: " << So_du << endl;

	cout << "Ngay phat hanh: " << Ngay_phat_hanh << endl;

	for (int i = 0; i < Lich_su.size(); i++)
		Lich_su[i].Xuat();

}
