#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

#include "thuvien.h"
#include "menu.h"	

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 0;
}

void ChayChuongTrinh()
{
	LIST ls;
	CreateEmptyList(ls); // Init an empty list

	int menu, soMenu = 9, kq = 0;
	char filename[MAX];

	// Yeu cau nguoi dung nhap du lieu
	do
	{
		cout << "\nNhap ten file de mo: ";
		cin >> filename;
		kq = GetDataFromFile(filename, ls);
		if (kq == 0) cout << "\nTap tin " << filename << " khong ton tai!\n";
	} while (kq == 0);
	
	// Mo tap tin thanh cong
	cout << "\nMo tap tin " << filename << " thanh cong!";
	cout << "\nDanh sach nhan vien hien tai\n";
	Xuat_DS_NV(ls);
	system("pause");

	// Xu ly menu chuong trinh
	do
	{
		system("cls");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, ls);
	} while (menu > 0);
}
