#include <iostream>
#include <fstream>

using namespace std;

#include "Thuvien.h"

int main()
{
	LIST list;

	char tenTapTin[30];
	int kq;

	cout << "\nNhap vao ten tap tin de mo: ";
	cin >> tenTapTin;

	kq = TaoDSTuFile(list, tenTapTin);
	if (kq == 0)
	{
		cout << "\nKhong the mo tap tin: " << tenTapTin << "\n";
		cout << "\nVui long kiem tra lai ten tap tin.\n";
	}
	else
	{
		cout << "\nMo tap tin thanh cong.";
		cout << "\nDanh sach nhan vien hien tai: ";
		XuatDS(list);
	}
	
	return 0;
}

