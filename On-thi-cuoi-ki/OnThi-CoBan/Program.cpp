#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Thuvien.h"

int main()
{
	LIST list;

	char tenTapTin[30];
	int kq;
	NhanVien nv;
	NODE* res;

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

		cout << "\nNhap ten nhan vien can tim kiem: ";
		cin >> nv.Ten;

		res = TimTenNV(list, nv.Ten);
		if (res == NULL)
			cout << "\nKhong tim thay nhan vien co ten: " << nv.Ten << endl;
		else
		{
			cout << "\nTim thay nhan vien co ten: " << nv.Ten << " trong danh sach.";
			cout << "\nTai vi tri: #" << TimViTriNODE(list, res) << endl;
		}
	}
	
	return 0;
}

