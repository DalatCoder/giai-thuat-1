void XuatMenu()
{
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Tao cay nhi phan tim kiem";
	cout << "\n2. Xem cay nhi phan theo thu tu L - N - R";
	cout << "\n3. Tinh so nut cua cay";
	cout << "\n4. Dem so nut co gia tri < x va xuat ra man hinh";
	cout << "\n5. Tim nut co khoa x cho truoc";
	cout << "\n6. Kiem tra x co phai la nut la";
	cout << "\n7. Dem so nut la cua cay";
	cout << "\n8. Xac dinh chieu cao cua cay";
	cout << "\n9. Xac dinh muc cua nut co khoa x";
	cout << "\n10. So sanh muc cua 2 nut";
	cout << "\n11. Them mot khoa x vao cay nhi phan tim kiem";
	cout << "\n12. Huy nut co khoa x cho truoc";
}

int ChonMenu(int somenu)
{
	int chon;

	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nChon chuc nang trong khoang [1.." << somenu << "] >> ";
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
	Data x, y;
	BSTree ketqua;

	cout << "\n";
	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat chuong trinh";
		break;
	case 1:
		cout << "\n1. Tao cay nhi phan tim kiem";
		cout << "\nNhap ten file de mo: ";
		cin >> filename;

		kq = GetDataFromFile(filename, root);

		if (kq)
			cout << "\nDa chuyen du lieu tu file " << filename << " vao cay BNS Tree.\n";
		else
			cout << "\nMo file " << filename << " khong thanh cong.\n";
		break;
	case 2:
		cout << "\n2. Xem cay nhi phan theo thu tu L - N - R";
		cout << "\nXuat cay theo thu tu giua:\n";
		InOrder(root);
		break;
	case 3:
		cout << "\n3. Tinh so nut cua cay";
		kq = DemSoNut(root);
		if (kq == 0) cout << "\nCay khong co nut\n";
		else
			cout << "\nSo nut hien tai cua cay la: " << kq << endl;
		break;
	case 4:
		cout << "\n4. Dem so nut co gia tri < x va xuat ra man hinh";
		cout << "\nNhap gia tri x: ";
		cin >> x;

		kq = DemNutNhoHon(root, x);
		cout << "\nSo nut nho hon gia tri x cho truoc la: " << kq << endl;
		break;
	case 5:
		cout << "\n5. Tim nut co khoa x cho truoc";
		cout << "\nNhap gia tri x: ";
		cin >> x;

		ketqua = Search(x, root);

		if (ketqua)
			cout << "\nTim ra nut co khoa x: = " << ketqua->data << endl;
		else
			cout << "\nKhong tim ra nut co khoa x cho truoc!" << endl;

		break;
	case 6:
		cout << "\n6. Kiem tra x co phai la nut la";
		cout << "\nNhap gia tri x: ";
		cin >> x;

		kq = IsLeaf_x(root, x);

		if (kq) cout << endl << x << " la nut la" << endl;
		else cout << "\nX khong phai la nut la!" << endl;

		break;
	case 7:
		cout << "\n7. Dem so nut la cua cay";
		kq = DemNutLa(root);

		cout << "\nSo nut la cua cay la: " << kq << endl;
		break; 
	case 8:
		cout << "\n8. Xac dinh chieu cao cua cay";

		kq = TinhChieuCao(root);

		if (kq == -1) cout << "\nCay khong ton tai!";
		else if (kq == 0) cout << "\nCay chi co nut goc!";
		else cout << "\nCay co chieu cao = " << kq;
		break;
	case 9:
		cout << "\n9. Xac dinh muc cua nut co khoa x";
		cout << "\nNhap gia tri x: ";
		cin >> x;

		kq = TimMuc_x(root, x);

		if (kq == 0) cout << "\nX la nut goc!";
		else
			cout << "\nMuc hien tai cua nut X la : " << kq << endl;

		break;
	case 10:
		cout << "\n10. So sanh muc cua 2 nut";
		cout << "\nNhap gia tri x: ";
		cin >> x;

		cout << "\nNhap gia tri y: ";
		cin >> y;

		kq = SoSanhMuc(root, x, y);

		if (kq > 0) cout << "\nX co muc cao hon Y" << endl;
		else if (kq < 0) cout << "\nX co muc thap hon Y" << endl;
		else cout << "\nX va Y co muc ngang nhau" << endl;

		break;
	case 11:
		cout << "\n11. Them mot khoa x vao cay nhi phan tim kiem";
		cout << "\nNhap gia tri x: ";
		cin >> x;

		kq = InsertNode(root, x);

		if (kq == 0) cout << "\nNut X da ton tai!" << endl;
		else if (kq == -1) cout << "\nLoi cap phat dong! Tao nut khong thanh cong!" << endl;
		else cout << "\nChen nut X vao cay thanh cong!" << endl;

		break;
	case 12:
		cout << "\n12. Huy nut co khoa x cho truoc";
		cout << "\nNhap gia tri x: ";
		cin >> x;

		kq = DeleteNode(x, root);

		if (kq) cout << "\nXoa nut X khoi cay thanh cong!" << endl;
		else cout << "\nXoa nut X khong thanh cong!" << endl;

		break;
	}

	cout << endl;
	system("pause");
}
