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
	char maNV[10];
	unsigned int namsinh;
	int kq;
	BSTree ketqua;

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

		kq = DemSoNut(root);

		if (kq == 0) cout << "\nCay hien tai khong co nut\n";
		else cout << "\nSo nut hien tai cua cay la: " << kq << endl;
		break;
	case 4:
		cout << "\n4. Thay doi nam sinh cua nhan vien co ma so nhan vien cho truoc";
		cout << "\nNhap vao ma nhan vien: ";
		cin >> maNV; 
		ketqua = Search(maNV, root);
		if (ketqua)
		{
			cout << "\nThong tin cua nhan vien: \n";
			XuatNV(ketqua->data);

			cout << "\nNhap vao nam sinh: ";
			cin >> namsinh;

			ketqua->data.namsinh = namsinh;

			cout << "\nThong tin nhan vien sau khi cap nhat:\n";
			XuatNV(ketqua->data);
		}
		else cout << "\nKhong tim thay nhan vien co ma so: " << maNV << endl;
		break;
	case 5:
		cout << "\n5. Huy nhan vien co ma nhan vien cho truoc";
		cout << "\nNhap vao ma nhan vien: ";
		cin >> maNV;

		ketqua = Search(maNV, root);
		if (ketqua)
		{
			kq = DeleteNode(maNV, root);

			if (kq) cout << "\nXoa thanh cong nhan vien co maNV: " << maNV << endl;
			else cout << "\nCo loi xay ra trong qua trinh!" << endl;
		}
		else cout << "\nKhong tim thay nhan vien co ma so: " << maNV << endl;

		break;
	}

	cout << endl;
	system("pause");
}

