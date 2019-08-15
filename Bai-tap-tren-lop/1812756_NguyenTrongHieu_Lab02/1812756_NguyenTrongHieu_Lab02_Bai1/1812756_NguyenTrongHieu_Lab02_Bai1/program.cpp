#include <iostream>
#include <fstream>

using namespace std;

#include "thuvien.h";
#include "menu.h";

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 0;
}

void ChayChuongTrinh()
{
	int a[MAX], n = 0;
	int menu, soMenu = 6;

	char filename[MAX];
	cout << "\n1. Doc mang tu file";
	cout << "\nNhap ten file: ";
	cin >> filename;
	docTapTin(filename, a, n);
	cout << "\nDay so vua doc la: \n";
	XuatMang(a, n);

	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(a, n, menu);
	} while (menu > 0);

	system("PAUSE");
}
