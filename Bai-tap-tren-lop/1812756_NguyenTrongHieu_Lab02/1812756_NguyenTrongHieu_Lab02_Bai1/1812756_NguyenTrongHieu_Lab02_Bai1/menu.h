void XuatMenu();
int ChonMenu(int somenu);
void XuLyMenu(int a[MAX], int &n, int menu);

void XuatMenu()
{
	cout << "\n=============DANH SACH CHUC NANG===============\n";

	cout << "\n1. Doc mang tu file";
	cout << "\n2. Xuat mang";
	cout << "\n3. Tim kiem tuyen tinh tra ve chi so tim thay";
	cout << "\n4. Tim kiem tuyen tinh co linh canh";
	cout << "\n5. Tim kiem nhi phan tra ve chi so tim thay";
	cout << "\n6. Tim kiem noi suy";
	cout << "\n0. Thoat chuong trinh";
}

int ChonMenu(int somenu)
{
	int chon;

	while (true)
	{
		system("CLS");
		XuatMenu();
		cout << "\nChon chuc nang tu 1 .. " << somenu << " : ";
		cin >> chon;
		if (0 <= chon && chon <= somenu)
			break;
	}

	return chon;
}

void XuLyMenu(int a[MAX], int &n, int menu)
{
	char filename[MAX];
	int x, kq;

	switch (menu)
	{
		case 1:		
			cout << "\n1. Doc mang tu file";
			cout << "\nNhap ten file: ";
			cin >> filename;
			docTapTin(filename, a, n);
			cout << "\nDay so vua doc la: \n";
			XuatMang(a, n);
			break;
		case 2:
			cout << "\n2. Xuat mang";
			cout << "\nMang hien tai la: \n";
			XuatMang(a, n);
			break;
		case 3:
			cout << "\n3. Tim kiem tuyen tinh tra ve chi so tim thay";
			cout << "\nMang hien tai la: \n";
			XuatMang(a, n);
			cout << "\nNhap vao 1 phan tu de tim kiem: ";
			cin >> x;
			kq = TimKiem_TT(a, n, x);
			if (kq == -1)
				cout << "\nKhong tim thay phan tu " << x << " trong mang a.";
			else
				cout << "\nTim thay phan tu " << x << " tai vi tri thu " << (kq + 1) << ".";
				break;
		case 4:
			cout << "\n4. Tim kiem tuyen tinh co linh canh";
			cout << "\nMang hien tai la: \n";
			XuatMang(a, n);
			cout << "\nNhap vao 1 phan tu de tim kiem: ";
			cin >> x;
			kq = TimKiem_TT_LC(a, n, x);
			if (kq == -1)
				cout << "\nKhong tim thay phan tu " << x << " trong mang a.";
			else
				cout << "\nTim thay phan tu " << x << " tai vi tri thu " << (kq + 1) << ".";
			break;
		case 5:
			cout << "\n5. Tim kiem nhi phan tra ve chi so tim thay";
			cout << "\nMang hien tai la: \n";
			XuatMang(a, n);

			SapXepMang(a, n);
			cout << "\nMang sap xep tang dan: \n";
			XuatMang(a, n);

			cout << "\nNhap vao 1 phan tu de tim kiem: ";
			cin >> x;
			kq = TimKiemNhiPhan(a, n, x);

			if (kq == -1)
				cout << "\nKhong tim thay phan tu " << x << " trong mang a.";
			else
				cout << "\nTim thay phan tu " << x << " tai vi tri thu " << (kq + 1) << ".";
			break;
		case 6:
			cout << "\n6. Tim kiem noi suy";
			break;
		case 0:
			cout << "\n0. Thoat chuong trinh";
			break;
	}

	cout << endl;
	system("PAUSE");
}

