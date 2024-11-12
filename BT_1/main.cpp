#include "TaiKhoanThanhToan.h"
#include "TaiKhoanTheHoanTien.h"
#include "TaiKhoanTheTichDiem.h"
#include "TaiKhoanTheTinDung.h"

void MenuTT(TaiKhoanThanhToan& Tai_khoan)
{
	while (true)
	{
		system("cls");
		cout << "1. Xuat thong tin the\n";
		cout << "2. Chuyen khoan\n";
		cout << "3. Xuat lich su giao dich\n";
		cout << "0. Tro lai man hinh chinh\n";
		int opt;
		do
		{
			cout << "Lua chon: ";
			cin >> opt;
		} while (opt < 0 || opt > 4);

		if (opt == 1)
		{
			Tai_khoan.Xuat();
			system("pause");
		}
		else if (opt == 2)
		{
			double soTien;
			cout << "Nhap so tien chuyen khoan: ";
			cin >> soTien;
			cin.ignore();
			if (Tai_khoan.transferTo(soTien))
				cout << "Chuyen khoan thanh cong\n";
			else
				cout << "Chuyen khoan khong thanh cong\n";
			system("pause");
		}
		else if (opt == 3) 
		{
			Tai_khoan.Xuat();
			system("pause");
		}
		else
		{
			break;
		}
	}
}

void MenuTTD(TaiKhoanTheTinDung& Tai_khoan) 
{
	while (true)
	{
		system("cls");
		cout << "1. Xuat thong tin the\n";
		cout << "2. Thanh toan\n";
		cout << "3. Thanh toan tin dung\n";
		cout << "4. Xuat lich su giao dich\n";
		cout << "0. Tro lai man hinh chinh\n";
		int opt;
		do
		{
			cout << "Lua chon: ";
			cin >> opt;
		} while (opt < 0 || opt > 4);

		if (opt == 1)
		{
			Tai_khoan.Xuat();
			system("pause");
		}
		else if (opt == 2)
		{
			double soTien;
			cout << "Nhap gia tri don hang: ";
			cin >> soTien;
			cin.ignore();
			if (Tai_khoan.charge(soTien))
				cout << "Thanh toan thanh cong\n";
			else
				cout << "Thanh toan khong thanh cong\n";
			system("pause");
		}
		else if (opt == 3) 
		{
			double soTien;
			cout << "Nhap so tien thanh toan the tin dung: ";
			cin >> soTien;
			Tai_khoan.payment(soTien);
			system("pause");
		}
		else if (opt == 4) 
		{
			Tai_khoan.showHistory();
			system("pause");
		}
		else 
		{
			break;
		}
	}
}

void MenuTTD(TaiKhoanTheTichDiem& Tai_khoan)
{
	while (1)
	{
		system("cls");
		cout << "1. Xuat thong tin the\n";
		cout << "2. Thanh toan\n";
		cout << "3. Thanh toan bang diem\n";
		cout << "4. Thanh toan tin dung\n";
		cout << "5. Xuat lich su giao dich\n";
		cout << "0. Tro lai man hinh chinh\n";
		int opt;
		do
		{
			cout << "Lua chon: ";
			cin >> opt;
		} while (opt < 0 || opt > 4);

		if (opt == 1)
		{
			Tai_khoan.Xuat();
			system("pause");
		}
		else if (opt == 2)
		{
			double soTien;
			cout << "Nhap gia tri don hang: ";
			cin >> soTien;
			cin.ignore();
			if (Tai_khoan.charge(soTien))
				cout << "Thanh toan thanh cong\n";
			else
				cout << "Thanh toan khong thanh cong\n";
			system("pause");
		}
		else if (opt == 3)
		{
			double soTien;
			cout << "Nhap gia tri don hang: ";
			cin >> soTien;
			Tai_khoan.payment(soTien);
			system("pause");
		}
		else if (opt == 4) 
		{
			double soTien;
			cout << "Nhap so tien thanh toan tin dung: ";
			cin >> soTien;
			Tai_khoan.payment(soTien);
			system("pause");
		}
		else if (opt == 5)
		{
			Tai_khoan.Xuat();
			system("pause");
		}
		else 
		{
			break;
		}
	}
}

void MenuTHT(TaiKhoanTheHoanTien& Tai_khoan)
{
	while (1)
	{
		system("cls");
		cout << "1. Xuat thong tin the\n";
		cout << "2. Thanh toan\n";
		cout << "3. Hoan tien\n";
		cout << "4. Thanh toan tin dung\n";
		cout << "5. Xuat lich su giao dich\n";
		cout << "0. Tro lai man hinh chinh\n";
		int opt;
		do 
		{
			cout << "Lua chon: ";
			cin >> opt;
		} while (opt < 0 || opt > 5);

		if (opt == 1) {
			Tai_khoan.Xuat();
			system("pause");
		}
		else if (opt == 2)
		{
			double soTien;
			cout << "Nhap gia tri don hang: ";
			cin >> soTien;
			cin.ignore();
			if (Tai_khoan.charge(soTien))
				cout << "Thanh toan thanh cong\n";
			else
				cout << "Thanh toan khong thanh cong\n";
			system("pause");
		}
		else if (opt == 3)
		{
			Tai_khoan.redeemCashBack();
			cout << "Hoan tien thanh cong\n";
			system("pause");
		}
		else if (opt == 4)
		{
			double soTien;
			cout << "Nhap so tien thanh toan tin dung: ";
			cin >> soTien;
			Tai_khoan.payment(soTien);
			system("pause");
		}
		else if (opt == 5)
		{
			Tai_khoan.Xuat();
			system("pause");
		}
		else
		{
			break;
		}
	}
}
void main()
{
	while (1)
	{
		system("cls");
		int opt;
		cout << "1. Tai khoan thanh toan\n";
		cout << "2. Tai khoan tin dung\n";
		cout << "3. Tai khoan tich diem\n";
		cout << "4. Tai khoan hoan tien\n";
		cout << "0. Thoat\n";
		do
		{
			cout << "Lua chon: ";
			cin >> opt;
			cin.ignore();
		} while (opt < 0 || opt > 4);

		if (opt == 1) 
		{
			TaiKhoanThanhToan Tai_khoan;
			Tai_khoan.Nhap();
			MenuTT(Tai_khoan);
		}
		else if (opt == 2) 
		{
			TaiKhoanTheTinDung Tai_khoan;
			Tai_khoan.Nhap();
			MenuTTD(Tai_khoan);
		}
		else if (opt == 3)
		{
			TaiKhoanTheTichDiem Tai_khoan;
			Tai_khoan.Nhap();
			MenuTTD(Tai_khoan);
		}
		else if (opt == 4) 
		{
			TaiKhoanTheHoanTien Tai_khoan;
			Tai_khoan.Nhap();
			MenuTHT(Tai_khoan);
		}
		else
		{
			cout << "Exit...\n";
			break;
		}
	}
}