void XuatMenu();
int ChonMenu(int somenu);
void XuLyMenu(int menu, NhanVien a[], int &n);

void XuatMenu()
{
	cout << "\n========= HE THONG CHUC NANG =========\n";
	cout << "\n1. Tao danh sach nhan vien.";
	cout << "\n2. Xem danh sach nhan vien.";
	cout << "\n3. Tang dan theo ma NV (chon truc tiep).";
	cout << "\n4. Tang dan theo dia chi (chen truc tiep).";
	cout << "\n5. Tang dan theo tien luong (doi cho truc tiep).";
	cout << "\n6. Giam dan theo ma NV (chen nhi phan).";
	cout << "\n7. Tang dan theo tien luong (heap sort).";
	cout << "\n8. Tang dan theo nam sinh (quick sort).";
	cout << "\n0. Thoat chuong trinh";
}

int ChonMenu(int somenu)
{
	int menu;

	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nChon chuc nang >> ";
		cin >> menu;

		if (0 <= menu && menu <= somenu)
			break;
	}

	return menu;
}

void XuLyMenu(int menu, NhanVien a[], int &n)
{

	char filename[MAX];
	int kq;

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
		cout << "\n3. Tang dan theo ma NV (chon truc tiep).";
		cout << "\nDanh sach nhan vien truoc khi sap xep: \n";
		Xuat_DS_NV(a, n);

		cout << "\nDanh sach nhan vien sau khi sap xep tang dan theo ma so: \n";
		Tang_MaNV(a, n);
		Xuat_DS_NV(a, n);
		break;
	case 4:
		cout << "\n4. Tang dan theo dia chi (chen truc tiep).";
		cout << "\nDanh sach nhan vien truoc khi sap xep: \n";
		Xuat_DS_NV(a, n);

		cout << "\nDanh sach nhan vien sau khi sap xep tang dan theo dia chi: \n";
		Tang_DiaChi(a, n);
		Xuat_DS_NV(a, n);
		break;
	case 5:
		cout << "\n5. Tang dan theo tien luong (doi cho truc tiep).";
		cout << "\nDanh sach nhan vien truoc khi sap xep: \n";
		Xuat_DS_NV(a, n);

		cout << "\nDanh sach nhan vien sau khi sap xep tang dan theo tien luong: \n";
		Tang_Luong(a, n);
		Xuat_DS_NV(a, n);
		break;
	case 6:
		cout << "\n6. Giam dan theo ma NV (chen nhi phan).";
		break;
	case 7:
		cout << "\n7. Tang dan theo tien luong (heap sort).";
		break;
	case 8:
		cout << "\n8. Tang dan theo nam sinh (quick sort).";
		cout << "\nDanh sach nhan vien truoc khi sap xep: \n";
		Xuat_DS_NV(a, n);

		cout << "\nDanh sach nhan vien sau khi sap xep tang dan theo tien luong: \n";
		QuickSort(a, 0, n - 1);
		Xuat_DS_NV(a, n);
		break;
	case 0:
		cout << "\nThoat chuong trinh!\n";
		break;
	}

	system("pause");
}