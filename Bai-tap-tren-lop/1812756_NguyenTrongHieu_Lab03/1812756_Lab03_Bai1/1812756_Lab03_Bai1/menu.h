void XuatMenu();
int ChonMenu(int somenu);
void XuLyMenu(int menu, LIST& l);

void XuatMenu()
{
	cout << "\n========= HE THONG CHUC NANG =========\n";
	cout << "\n1. Nhap danh sach lien ket tu file";
	cout << "\n2. Xuat danh sach lien ket";
	cout << "\n3. Tinh tong cac phan tu trong danh sach";
	cout << "\n4. Tim phan tu lon nhat trong danh sach";
	cout << "\n5. Tim X (First node)";
	cout << "\n6. Tim X (Final node)";
	cout << "\n7. Chen X vao dau danh sach";
	cout << "\n8. Chen X vao cuoi danh sach";
	cout << "\n9. Chen X vao sau node Y trong danh sach";
	cout << "\n10. Huy nut cuoi";
	cout << "\n11. Huy nut dau";
	cout << "\n12. Huy nut dau tien chua du lieu X";
	cout << "\n13. Huy toan bo danh sach";
	cout << "\n14. Sap tang danh sach (Chon doi du lieu)";
	cout << "\n15. Sap tang danh sach (hoan doi lien ket)";
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

void XuLyMenu(int menu, LIST &ls)
{
	char filename[MAX];
	int kq;

	switch (menu)
	{
		case 1:
			cout << "\n1. Nhap danh sach lien ket tu file";
			cout << "\nNhap ten file de mo: ";
			cin >> filename;

			kq = GetDataFromFile(filename, ls);
			if (!kq)
			{
				cout << "\nKhong the mo tap tin! Vui long kiem tra lai ten tap tin!";
				return;
			}

			DisplayList(ls);
			break;
		case 2:
			cout << "\n2. Xuat danh sach lien ket";
			DisplayList(ls);
			break;
		case 3:
			cout << "\n3. Tinh tong cac phan tu trong danh sach";
			break;
		case 4:
			cout << "\n4. Tim phan tu lon nhat trong danh sach";
			break;
		case 5:
			cout << "\n5. Tim X (First node)";
			break;
		case 6:
			cout << "\n6. Tim X (Final node)";
			break;
		case 7:
			cout << "\n7. Chen X vao dau danh sach";
			break;
		case 8:
			cout << "\n8. Chen X vao cuoi danh sach";
			break;
		case 9:
			cout << "\n9. Chen X vao sau node Y trong danh sach";
			break;
		case 10:
			cout << "\n10. Huy nut cuoi";
			break;
		case 11:
			cout << "\n11. Huy nut dau";
			break;
		case 12:
			cout << "\n12. Huy nut dau tien chua du lieu X";
			break;
		case 13:
			cout << "\n13. Huy toan bo danh sach";
			break;
		case 14:
			cout << "\n14. Sap tang danh sach (Chon doi du lieu)";
			break;
		case 15:
			cout << "\n15. Sap tang danh sach (hoan doi lien ket)";
			break;
		case 0:
			cout << "\nThoat chuong trinh!\n";
			break;
	}

	cout << endl;
	system("pause");
}