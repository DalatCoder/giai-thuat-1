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

		res = TimNVLuongCaoNhat(list);
		if (res == NULL)
			cout << "\nDanh sach hien tai rong.\n";
		else
		{
			cout << "\nNhan vien co muc luong cao nhat: $" << res->info.Luong;
			cout << "\nTai vi tri: #" << TimViTriNODE(list, res);
			cout << "\nThong tin chi tiet cua nhan vien:\n";
			Xuat1NV(res->info);
		}

		cout << "\nNhap vao muc luong toi thieu: $";
		cin >> nv.Luong;

		kq = DemTheoLuong(list, nv.Luong);
		if (kq == 0)
			cout << "\nKhong tim thay nhan vien co muc luong >= " << nv.Luong << endl;
		else
			cout << "\nTim thay " << kq << " nhan vien co muc luong >= " << nv.Luong;
	}
	
	return 0;
}

