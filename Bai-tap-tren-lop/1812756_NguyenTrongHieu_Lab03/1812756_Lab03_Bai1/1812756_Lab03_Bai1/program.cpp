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
	int menu, soMenu = 15;
	LIST ls;
	CreateEmptyList(ls); // Khoi tao danh sach trong
	char filename[MAX];
	int kq;

	do
	{
		cout << "\nNhap ten file de mo: ";
		cin >> filename;

		kq = GetDataFromFile(filename, ls);
		if (!kq)
		{
			cout << "\nKhong the mo tap tin! Vui long kiem tra lai ten tap tin!";
		}
	} while (kq == 0);

	cout << "\nMo tap tin thanh cong!\n";
	DisplayList(ls);

	do
	{
		system("cls");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, ls);
	} while (menu > 0);
}