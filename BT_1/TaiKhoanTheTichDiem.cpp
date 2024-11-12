#include"TaiKhoanTheTichDiem.h"

TaiKhoanTheTichDiem::TaiKhoanTheTichDiem()
{
}

TaiKhoanTheTichDiem::~TaiKhoanTheTichDiem()
{
}

int TaiKhoanTheTichDiem::getCurrentPoints()
{
	return this->currentPoints;
}

bool TaiKhoanTheTichDiem::charge(double amount)
{
	if (So_du + amount <= Han_muc_tin_dung)
	{
		string temp;
		So_du = So_du + amount;
		currentPoints = (int)amount * rewardRate;
		cout << "Nhap ngay hien tai(dd/MM/yyyy): ";
		getline(cin, temp);
		LichSuGiaoDich ls(So_tai_khoan, amount, "Thanh toan hoa don", temp);
		Lich_su.push_back(ls);
		currentPoints = unsigned(amount * rewardRate);
		return true;
	}	
	else
		return false;
}

void TaiKhoanTheTichDiem::payWithPoints(int pAmount)
{
	if (pAmount > currentPoints) {}
	else
	{
		string temp;
		currentPoints = currentPoints - pAmount;
		cout << "Nhap ngay hien tai(dd/MM/yyyy): ";
		getline(cin, temp);
		LichSuGiaoDich ls(So_tai_khoan, pAmount, "Thanh toan bang diem", temp);
		Lich_su.push_back(ls);
	}
}

void TaiKhoanTheTichDiem::Nhap()
{
	cout << "Nhap so tai khoan: ";
	getline(cin, So_tai_khoan);

	cout << "Nhap so du: ";
	cin >> So_du;
	cin.ignore();

	cout << "Nhap ngay phat hanh(dd/MM/yyyy): ";
	getline(cin, Ngay_phat_hanh);

	cout << "Nhap he so thuong: ";
	cin >> rewardRate;
	cin.ignore();
}

void TaiKhoanTheTichDiem::Xuat()
{
	cout << "So tai khoan: " << So_tai_khoan << endl;

	cout << "So du: " << So_du << endl;

	cout << "Ngay phat hanh(dd/MM/yyyy): " << Ngay_phat_hanh << endl;

	cout << "Diem hien tai: " << currentPoints << endl;
}
