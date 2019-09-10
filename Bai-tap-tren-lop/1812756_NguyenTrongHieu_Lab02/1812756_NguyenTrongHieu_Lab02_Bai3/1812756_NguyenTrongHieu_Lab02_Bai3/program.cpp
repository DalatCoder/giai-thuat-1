#include <iostream>
#include <fstream>

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
	int a[MAX], n;
	int menu, soMenu = 7;

	// Yeu cau nhap danh sach nhan vien dau tien
	char filename[MAX];
	int kq;

	do
	{
		cout << "\nNhap ten tap tin de mo >> ";
		cin >> filename;

		kq = DocMang(a, n, filename);
	} while (kq == 0);

	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
	} while (menu > 0);

	system("pause");
}
