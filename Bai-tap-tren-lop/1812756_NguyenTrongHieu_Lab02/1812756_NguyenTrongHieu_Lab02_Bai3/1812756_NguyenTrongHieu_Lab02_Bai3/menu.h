#pragma once
void XuatMenu();
int  ChonMenu(int soMenu);
void XuLyMenu(int menu, int a[], int &n);

void XuatMenu()
{
	cout << "\n===============HE THONG CHUC NANG===============\n";
	cout << "\n1. Doc mang tu file";
	cout << "\n2. Xuat mang";
	cout << "\n3. Chon truc tiep";
	cout << "\n4. Chen truc tiep";
	cout << "\n5. Doi cho truc tiep";
	cout << "\n6. Noi bot";
	cout << "\n7. Chen nhi phan";
	cout << "\n0. Thoat chuong trinh";
}

int ChonMenu(int soMenu)
{
	int chon;

	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nChon 1 chuc nang >> ";
		cin >> chon;

		if (0 <= chon && chon <= soMenu)
			break;
	}

	return chon;
}

void XuLyMenu(int menu, int a[], int& n)
{
	char filename[MAX];
	int kq;

	switch (menu)
	{
	case 1:
		cout << "\n1. Doc mang tu file";
		cout << "\nNhap ten tap tin >> ";
		cin >> filename;

		kq = DocMang(a, n, filename);

		if (!kq)
		{
			cout << "\nLoi mo tap tin (" << filename << "). Vui long kiem tra lai ten tap tin!";
			cout << endl;
			system("pause");
			exit(-1);
		}

		cout << "\nMo tap tin thanh cong! Noi dung tap tin: \n";
		XuatMang(a, n);

		break;

	case 2:
		cout << "\n2. Xuat mang";
		cout << "\nMang hien tai gom " << n << " phan tu: \n";
		XuatMang(a, n);
		break;

	case 3:
		cout << "\n3. Chon truc tiep";
		cout << "\nMang truoc khi sap xep: \n";
		XuatMang(a, n);

		ChonTrucTiep(a, n);
		break;
	case 4:
		cout << "\n4. Chen truc tiep";
		cout << "\nMang truoc khi sap xep: \n";
		XuatMang(a, n);

		chenTrucTiep(a, n);
		break;
	case 5:
		cout << "\n5. Doi cho truc tiep";
		cout << "\nMang truoc khi sap xep: \n";
		XuatMang(a, n);

		DoiChoTrucTiep(a, n);
		break;
	case 6:
		cout << "\n6. Noi bot";
		cout << "\nMang truoc khi sap xep: \n";
		XuatMang(a, n);

		bubbleSort(a, n);
		break;
	case 7:
		cout << "\n7. Chen nhi phan";
		break;
	case 0:
		cout << "\n0. Thoat chuong trinh";
		break;
	}
	system("pause");
}
