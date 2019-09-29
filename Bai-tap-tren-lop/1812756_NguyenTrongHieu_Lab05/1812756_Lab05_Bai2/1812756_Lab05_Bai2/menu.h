void XuatMenu()
{
	cout << "\n========== HE THONG CHUC NANG =============\n";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Tao bang luong nhan vien";
	cout << "\n2. Xem bang luong nhan vien theo thu tu";
	cout << "\n3. Tinh so nut cua cay";
	cout << "\n4. Thay doi nam sinh cua nhan vien co ma nhan vien cho truoc";
	cout << "\n5. Huy nhan vien co maNV cho truoc";
}

int ChonMenu(int somenu)
{
	int chon;

	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nChon 1 chuc nang trong khoang tu [1.." << somenu << "] >> ";
		cin >> chon;

		if (0 <= chon && chon <= somenu)
			break;
	}

	return chon;
}

void XuLyMenu(int menu, BSTree &root)
{
	char filename[50];
	int kq;


	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat chuong trinh";
		break;
	case 1:
		cout << "\n1. Tao bang luong nhan vien"; 
		cout << "\nNhap ten tap tin de mo: ";
		cin >> filename;

		kq = GetDataFromFile(filename, root);

		if (kq) cout << "\nDoc du lieu tu tap tin " << filename << " thanh cong!";
		else cout << "\nDoc du lieu khong thanh cong!";
		break;
	case 2:
		cout << "\n2. Xem bang luong nhan vien theo thu tu"; 
		cout << "\nBang luong nhan vien theo thu tu giua - truoc - sau:\n";
		PreOrder(root);

		cout << "\nBang luong nhan vien theo thu tu truoc - giua - sau:\n";
		InOrder(root);

		cout << "\nBang luong nhan vien theo thu tu truoc - sau - giua:\n";
		PosOrder(root);
		break;
	case 3:
		cout << "\n3. Tinh so nut cua cay";
		break;
	case 4:
		cout << "\n4. Thay doi nam sinh cua nhan vien co ma so nhan vien cho truoc";
		break;
	case 5:
		cout << "\n5. Huy nhan vien co ma nhan vien cho truoc";
		break;
	}

	cout << endl;
	system("pause");
}

