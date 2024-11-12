#include"LichSuGiaoDich.h"

LichSuGiaoDich::LichSuGiaoDich()
{
}

LichSuGiaoDich::LichSuGiaoDich(string tai_khoan, double so_tien, string noi_dung, string ngay)
{
	So_tai_khoan = tai_khoan;
	So_tien_chuyen_khoan = so_tien;
	Noi_dung_chuyen_khoan = noi_dung;
	Ngay_giao_dich = ngay;
}

LichSuGiaoDich::~LichSuGiaoDich()
{
}

void LichSuGiaoDich::Nhap()
{
	string temp;
	cout << "Nhap so tai khoan: ";
	getline(cin, So_tai_khoan);

	cout << "Nhap so tien chuyen khoan: ";
	cin >> So_tien_chuyen_khoan;
	cin.ignore();

	cout << "Nhap noi dung chuyen khoan: ";
	getline(cin, Noi_dung_chuyen_khoan);

	cout << "Nhap ngay: ";
	getline(cin, Ngay_giao_dich);

}

void LichSuGiaoDich::Xuat()
{
	cout << "So tai khoan: " << So_tai_khoan<<endl;

	cout << "So tien chuyen khoan: " << So_tien_chuyen_khoan<<endl;

	cout << "Noi dung chuyen khoan: " << Noi_dung_chuyen_khoan<<endl;

	cout << "Ngay: " << Ngay_giao_dich<<endl;
}
