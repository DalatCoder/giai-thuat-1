void XuatMenu();
int ChonMenu(int somenu);
void XuLyMenu(int menu, LIST &ls);

void XuatMenu()
{
	cout << "\n========= HE THONG CHUC NANG =========\n";
	cout << "\n1. Nhap danh sach nhan vien tu file";
	cout << "\n2. Xuat danh sach nhan vien";
	cout << "\n3. Tim theo ten nhan vien - Final Node";
	cout << "\n4. Tim nhan vien co luong cao nhat";
	cout << "\n5. Dem nhan vien co tien luong >= X";
	cout << "\n6. Huy toan bo nhan vien co dia chi X";
	cout << "\n7. Huy nhan vien dau tien co ten X";
	cout << "\n8. Sap giam theo nam sinh (Buble sort)";
	cout << "\n9. Sap giam ma nhan vien (Chen Truc Tiep)";
	cout << "\n10. Sap tang luong nhan vien (Chon truc tiep)";
	cout << "\n11. Sap tang theo ten nhan vien (Doi cho truc tiep)";
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
	Data nhanvien;
	NODE* node = NULL;
	LIST list;

	switch (menu)
	{
	case 1:
		cout << "\n1. Nhap danh sach nhan vien tu file";
		cout << "\nNhap ten file de mo: ";
		cin >> filename;

		kq = GetDataFromFile(filename, ls);
		if (kq)
		{
			cout << "\nMo tap tin " << filename << " thanh cong!";
			cout << "\nDanh sach nhan vien hien tai\n";
			Xuat_DS_NV(ls);
		}
		else cout << "Tap tin " << filename << " khong ton tai!\n";
		break;

	case 2:
		cout << "\n2. Xuat danh sach nhan vien";
		cout << "\nDanh sach nhan vien hien tai\n";
		Xuat_DS_NV(ls);
		break;

	case 3:
		cout << "\n3. Tim theo ten nhan vien - Final Node";
		cout << "\nNhap ten nhan vien can tim kiem: ";
		cin >> nhanvien.name.ten;

		node = Get_Final_Employee_With_Name(ls, nhanvien.name.ten);
		if (node)
		{
			cout << "\nTim thay nhan vien co ten: " << nhanvien.name.ten;
			cout << "\nThong tin chi tiet ve nhan vien:\n";
			XuatTieuDe();
			Xuat_1_NV(node->info);
			XuatDuongKe('=');
		}
		else cout << "\nKhong tim thay nhan vien co ten: " << nhanvien.name.ten << endl;
		break;

	case 4:
		cout << "\n4. Tim nhan vien co luong cao nhat";
		node = Max_Salary(ls);
		cout << "\nThong tin chi tiet ve nhan vien co luong cao nhat:\n";
		XuatTieuDe();
		Xuat_1_NV(node->info);
		XuatDuongKe('=');
		break;

	case 5:
		cout << "\n5. Dem nhan vien co tien luong >= X";
		cout << "\nNhap muc luong toi thieu: ";
		cin >> nhanvien.luong;

		list = Filter_Employee(ls, nhanvien.luong);
		kq = Get_List_Length(list);
		if (kq == 0) 
			cout << "\nKhong tim thay nhan vien co muc luong >= " << nhanvien.luong << "\n";
		else
		{
			cout << "\nTim thay " << kq << " nhan vien co muc luong >= " << nhanvien.luong << "\n";
			cout << "\nDanh sach chi tiet: \n";
			Xuat_DS_NV(list);
		}
		break;

	case 6:
		cout << "\n6. Huy toan bo nhan vien co dia chi X";
		cout << "\nNhap dia chi cua nhan vien can xoa (cach bang dau _ VD: Lam_Dong) ";
		cin >> nhanvien.diaChi;

		if (IsAddressExist(ls, nhanvien.diaChi))
		{
			list = Xoa_TatCa_NODE_Co_DiaChi(ls, nhanvien.diaChi);
			if (IsEmptyList(list)) cout << "\nDanh sach hien tai rong!\n";
			else
			{
				cout << "\nDanh sach nhan vien sau khi xoa tat ca nhan vien co dia chi " << nhanvien.diaChi << endl;
				Xuat_DS_NV(list);
			}
		}
		else cout << "\nKhong tim thay nhan vien co dia chi " << nhanvien.diaChi << endl;
		break;
	case 7:
		cout << "\n7. Huy nhan vien dau tien co ten X";
		cout << "\nNhap ten nhan vien can xoa khoi danh sach: ";
		cin >> nhanvien.name.ten;
		
		node = Get_First_Employee_With_Name(ls, nhanvien.name.ten);

		if (node)
		{
			list = Remove_Node(ls, node);
			cout << "\nDanh sach nhan vien sau khi xoa bo nhan vien dau tien co ten " << nhanvien.name.ten << endl;
			Xuat_DS_NV(list);
		}
		else cout << "\nKhong tim thay nhan vien co ten " << nhanvien.name.ten << " trong danh sach.\n";

		break;

	case 8:
		cout << "\n8. Sap giam theo nam sinh (Buble sort)";
		break;
	case 9:
		cout << "\n9. Sap giam ma nhan vien (Chen Truc Tiep)";
		break;
	case 10:
		cout << "\n10. Sap tang luong nhan vien (Chon truc tiep)";
		break;
	case 11:
		cout << "\n11. Sap tang theo ten nhan vien (Doi cho truc tiep)";
		break;
	case 0:
		cout << "\nThoat chuong trinh!\n";
		break;
	}

	system("pause");
}