
void XuatMenu();
int  ChonMenu(int soMenu);
void XuLyMenu(int menu);


void XuatMenu()
{
	cout << "\n============== DANH SACH CHUC NANG =================\n";
	cout << "\n1. Tim gia tri min, max";
	cout << "\n2. Hoan doi 2 phan trong 1 day";
	cout << "\n3. Liet ke day nhi phan do dai n";
	cout << "\n4. Bai toan ngua di tuan";
	cout << "\n0. Thoat chuong trinh";
}

int ChonMenu(int somenu)
{
	int stt;

	while (true)
	{
		system("CLS");
		XuatMenu();
		cout << "\nChon chuc nang tuong ung tu 0 .. " << somenu << " : ";
		cin >> stt;
		if (0 <= stt && stt <= somenu)
			break;
	}

	return stt;
}

void XuLyMenu(int menu)
{
	int a[MAX], n = 0;
	int l, r, min, max;
	int m;

	switch (menu)
	{
		case 0:
			cout << "\n0. Thoat chuong trinh"; 
			break;
		case 1:
			cout << "\n1. Tim gia tri min, max";
			NhapDay(a,n); // Nhap tu dong day a
			cout << "\nDay so vua tao ngau nhien: \n";
			XuatDay(a, n);

			NhapChiSo_Trai_Phai(l, r, n);
			MinMax(a, l, r, min, max);
			cout << "\nMin cua doan a[" << l << "..." << r << "] = " << min;
			cout << "\nMax cua doan a[" << l << "..." << r << "] = " << max;
			cout << endl;

			break;
		case 2:
			cout << "\n2. Hoan doi 2 phan trong 1 day";
			NhapDay(a, n); // Nhap tu dong day a
			cout << "\nChuoi truoc khi chuyen doi: \n";
			XuatDay(a, n);

			do
			{
				cout << "\nNhap so phan tu can chuyen doi: ";
				cin >> m;
			} while (m <= 0 || m >= n);

			ChuyenChuoi(a, n, m);

			cout << "\nChuoi sau khi chuyen doi: \n";
			XuatDay(a, n);

			break;
		case 3:
			cout << "\n3. Liet ke day nhi phan do dai n";

			do
			{
				cout << "\nNhap so do dai: ";
				cin >> n;
			} while (n <= 0 || n >= MAX);

			LietKe_NP(0, a, n);

			break;
		case 4:
			cout << "\n4. Bai toan ngua di tuan";
			break;
	}
}