#include "TaiKhoanTheHoanTien.h"

TaiKhoanTheHoanTien::TaiKhoanTheHoanTien()
{
}

TaiKhoanTheHoanTien::~TaiKhoanTheHoanTien()
{
}

int TaiKhoanTheHoanTien::getCurrentCashBack()
{
	return currentCashBack;
}

bool TaiKhoanTheHoanTien::charge(double amount)
{
	if (So_du + amount <= Han_muc_tin_dung)
	{
		string temp;

		So_du = So_du + amount;
		currentCashBack = int (amount * cashbackRate);

		cout << "Nhap ngay hien tai(dd/MM/yyyy): ";
		getline(cin, temp);
		LichSuGiaoDich ls(So_tai_khoan, amount, "Thanh toan hoan tien", temp);
		Lich_su.push_back(ls);

		return true;
	}
	else
		return false;
}

void TaiKhoanTheHoanTien::redeemCashBack()
{
	string temp;

	So_du = So_du - currentCashBack;
	currentCashBack = 0;
	cout << "Nhap ngay hien tai(dd/MM/yyyy): ";
	getline(cin, temp);
	LichSuGiaoDich ls(So_tai_khoan, currentCashBack, "Hoan tien", temp);
	Lich_su.push_back(ls);

}

void TaiKhoanTheHoanTien::Nhap()
{
	cout << "Nhap so tai khoan: ";
	getline(cin, So_tai_khoan);

	cout << "Nhap so du: ";
	cin >> So_du;
	cin.ignore();

	cout << "Nhap ngay phat hanh(dd/MM/yyyy): ";
	getline(cin, Ngay_phat_hanh);

	cout << "Nhap ti le hoan tien: ";
	cin >> cashbackRate;

	cout << "Nhap so tien hoan lai hien tai: ";
	cin >> currentCashBack;
}

void TaiKhoanTheHoanTien::Xuat()
{
	cout << "So tai khoan: " << So_tai_khoan << endl;

	cout << "So du: " << So_du << endl;

	cout << "Ngay phat hanh: " << Ngay_phat_hanh << endl;

	for (int i = 0; i < Lich_su.size(); i++)
		Lich_su[i].Xuat();

	cout << "Ti le hoan tien: " << cashbackRate << endl;

	cout << "So tien hoan lai hien tai: " << currentCashBack << endl;
}
