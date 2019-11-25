void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(LIST& l, int menu);


void XuatMenu()
{
	cout << "\nHe thong chuc nang\n";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Tao danh sach sinh vien tu tap tin";
	cout << "\n2. Xuat danh sach sinh vien hien tai";
	cout << "\n3. Tim thong tin nhan vien co muc luong cao nhat";
	cout << "\n4. Xuat toan bo nhan vien co muc luong lon hon X cho truoc";
	cout << "\n5. Tim nhan vien co ten X, tra ve NODE dau tien neu co";
	cout << "\n6. Huy nhan vien cuoi cung co ten X neu co";
	cout << "\n7. Sap tang theo nam sinh - tien luong";
	cout << "\n8. Tao danh sach nhan vien trung ho: (chen truoc)";
	cout << "\n9. Xoa tat ca nhan vien co nam sinh nho hon X";
	cout << "\n10. Sap xep danh sach nhan vien giam dan (chon truc tiep)";
}

int ChonMenu(int soMenu)
{
	int chon;

	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nChon 1 chuc nang tuong ung: ";
		cin >> chon;

		if (0 <= chon && chon <= soMenu)
			break;
	}
	
	return chon;
}

void XuLyMenu(LIST& l, int menu)
{
	char filename[20];
	int kq;
	NODE* res;
	double luong;
	int namSinh;
	char ten[10];
	char ho[10];
	LIST lkq;

	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat chuong trinh\n";
		break;
	case 1:
		cout << "\n1. Tao danh sach sinh vien tu tap tin";
		cout << "\nNhap ten tap tin can mo: ";
		cin >> filename;

		kq = TaoDSNhanVien(l, filename);
		if (kq == 0)
			cout << "\nKhong the mo tap tin '" << filename << "'! Vui long kiem tra lai ten tap tin.\n";
		else
		{
			cout << "\nMo tap tin thanh cong!";
			cout << "\nDanh sach nhan vien hien tai:\n";
			XuatDSNV(l);
		}
		break;
	case 2:
		cout << "\n2. Xuat danh sach sinh vien hien tai";
		cout << "\nDanh sach nhan vien hien tai:\n";
		XuatDSNV(l);
		break;
	case 3:
		cout << "\n3. Tim thong tin nhan vien co muc luong cao nhat";
		res = TimMaxLuong(l);

		if (res == NULL)
			cout << "\nDanh sach rong!\n";
		else
		{
			cout << "\nThong tin nhan vien co muc luong cao nhat:\n";
			Xuat1NV(res->info);
		}
		break;
	case 4:
		cout << "\n4. Xuat toan bo nhan vien co muc luong lon hon X cho truoc";
		cout << "\nNhap vao muc luong toi thieu: ";
		cin >> luong;

		lkq = TaoDSNhanVienCoLuongThoaDieuKien(l, luong);
		if (lkq.pHead == NULL)
			cout << "\nDanh sach nhan vien rong!\n";
		else
		{
			cout << "\nDanh sach nhan vien co muc luong lon hon " << luong << endl;
			XuatDSNV(lkq);
		}
		break;
	case 5:
		cout << "\n5. Tim nhan vien co ten X, tra ve NODE dau tien neu co";
		cout << "\nNhap ten nhan vien can tim: ";
		cin >> ten;

		res = TimNhanVienDauTien(l, ten);
		if (res == NULL)
			cout << "\nKhong tim thay nhan vien co ten '" << ten << "'!\n";
		else
		{
			cout << "\nThong tin chi tiet cua nhan vien dau tien co ten '" << ten << "':\n";
			Xuat1NV(res->info);
		}

		break;
	case 6:
		cout << "\n6. Huy nhan vien cuoi cung co ten X neu co";
		cout << "\nDanh sach nhan vien hien tai:\n";
		XuatDSNV(l);

		cout << "\nNhap ten nhan vien can xoa: ";
		cin >> ten;

		res = HuyNhanVienCuoiCung(l, ten);
		if (res == NULL)
			cout << "\nKhong tim thay nhan vien co ten '" << ten << "'!\n";
		else
		{
			cout << "\nThong tin nhan vien vua bi xoa:\n";
			Xuat1NV(res->info);

			cout << "\nDanh sach nhan vien sau khi xoa:\n";
			XuatDSNV(l);
		}
		break;
	case 7:
		cout << "\n7. Sap tang theo nam sinh - tien luong";
		cout << "\nDanh sach nhan vien ban dau:\n";
		XuatDSNV(l);

		SapTangDanQueQuan_NamSinh(l);
		cout << "\nDanh sach nhan vien sau khi sap xep tang dan theo que quan va nam sinh:\n";
		XuatDSNV(l);
		break;
	case 8:
		cout << "\n8. Tao danh sach nhan vien trung ho: (chen truoc)";
		cout << "\nNhap ho cua nhan vien: ";
		cin >> ho;

		lkq = TaoDSNhanVienTrungHo(l, ho);
		if (lkq.pHead == NULL)
			cout << "\nKhong co nhan vien co ho: '" << ho << "'!\n";
		else
		{
			cout << "\nDanh sach nhan vien co ho: '" << ho << "':\n";
			XuatDSNV(lkq);
		}
		
		break;
	case 9:
		cout << "\n9. Xoa tat ca nhan vien co nam sinh nho hon X";
		cout << "\nNhap nam sinh toi da: ";
		cin >> namSinh;
		lkq = TaoDSNhanVienCoNamSinhThoaDieuKien(l, namSinh);

		if (lkq.pHead == NULL)
			cout << "\nDanh sach rong!\n";
		else
		{
			cout << "\nDanh sach nhan vien sau khi xoa nhan vien co nam sinh nho hon " << namSinh << endl;
			XuatDSNV(lkq);
		}
		break;
	case 10:
		cout << "\n10. Sap xep danh sach nhan vien giam dan (chon truc tiep)";
		cout << "\nDanh sach nhan vien ban dau:\n";
		XuatDSNV(l);

		SapXep_Giam_MaNV(l);
		cout << "\nDanh sach nhan vien sau khi sap xep giam dan theo ma so:\n";
		XuatDSNV(l);
		break;
	}

	system("pause");
}




