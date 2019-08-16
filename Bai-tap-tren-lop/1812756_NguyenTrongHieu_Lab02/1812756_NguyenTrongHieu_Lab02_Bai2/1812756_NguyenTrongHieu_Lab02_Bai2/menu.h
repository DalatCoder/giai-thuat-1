#pragma once

void XuatMenu();
int ChonMenu(int somenu);
void XuLyMenu(int menu, NhanVien a[], int &n);


void XuatMenu()
{
	cout << "\n============ HE THONG CHUC NANG ===============\n";
	cout << "\n1. Doc danh sach nhan vien tu file";
	cout << "\n2. Xuat danh sach nhan vien";
	cout << "\n3. Tim kiem theo ho ten nhan vien";
	cout << "\n4. Tim kiem theo nam sinh";
	cout << "\n5. Tim kiem theo ho ten va nam sinh nho hon x cho truoc";
	cout << "\n6. Tim kiem theo ten va dia chi";
	cout << "\n7. Tim kiem theo luong >= x va nam sinh <= y";
	cout << "\n8. Tim kiem nhi phan theo ma nhan vien";
	cout << "\n0. Thoat chuong trinh";
}

int ChonMenu(int somenu)
{
	int chon;

	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nChon 1 chuc nang trong khoang 1.." << somenu << " >> ";
		cin >> chon;

		if (0 <= chon && chon <= somenu)
			break;
	}

	return chon;
}

void XuLyMenu(int menu, NhanVien a[], int &n)
{
	char filename[MAX];
	int kq;

	system("cls");
	switch (menu)
	{
		case 1:
			cout << "\n1. Doc danh sach nhan vien tu file";
			cout << "\nNhap ten file de mo >> ";
			cin >> filename;

			kq = DocDanhSachNhanVien(filename, a, n);
			if (kq != 0)
			{
				cout << "\nDanh sach nhan vien hien tai: (co " << n << " nhan vien).\n";
				Xuat_DS_NV(a, n);
			}

			break;
		case 2:
			cout << "\n2. Xuat danh sach nhan vien";
			cout << "\nDanh sach nhan vien hien tai: (co " << n << " nhan vien).\n";
			Xuat_DS_NV(a, n);
			break;
		case 3:
			cout << "\n3. Tim kiem theo ho ten nhan vien";
			break;
		case 4:
			cout << "\n4. Tim kiem theo nam sinh";
			break;
		case 5:
			cout << "\n5. Tim kiem theo ho ten va nam sinh nho hon x cho truoc";
			break;
		case 6:
			cout << "\n6. Tim kiem theo ten va dia chi";
			break;
		case 7:
			cout << "\n7. Tim kiem theo luong >= x va nam sinh <= y";
			break;
		case 8:
			cout << "\n8. Tim kiem nhi phan theo ma nhan vien";
			break;
		case 0:
			cout << "\n0. Thoat chuong trinh\n";
			break;
	}
	system("pause");
}
