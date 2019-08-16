#pragma once


void XuatMenu();
int  ChonMenu(int somenu);
void XuLyMenu(int menu, int &n);


void XuatMenu()
{
	cout << "\n=============== HE THONG MENU ===============\n";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap du lieu n";
	cout << "\n2. Xem du lieu n";
	cout << "\n3. Liet ke day nhi phan";
	cout << "\n4. Liet ke to hop";
	cout << "\n5. Liet ke hoan vi";
}

int ChonMenu(int somenu)
{
	int stt;

	while (true)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap 1 so trong khoang [0,...," << somenu << "] de chon menu (Lan dau tien chon 1), stt = ";
		cin >> stt;
		if (0 <= stt && stt <= somenu)
			break;
	}

	return stt;
}

void XuLyMenu(int menu, int &n)
{
	system("CLS");
	switch (menu)
	{
		case 0:
			cout << "\n0. Thoat khoi chuong trinh";
			cout << endl;
			break;
		case 1:
			cout << "\n1. Nhap du lieu n";
			cout << "\nNhap n = "; 
			cin >> n;
			cout << endl;
			break;
		case 2:
			cout << "\n2. Xem du lieu n";
			cout << "\nn = " << n;
			cout << endl;
			break;
		case 3:
			cout << "\n3. Liet ke day nhi phan";
			cout << endl;
			dem = 0;
			LietKe_DayNP(1);
			break;
		case 4:
			cout << "\n4. Liet ke to hop";
			break;
		case 5:
			cout << "\n5. Liet ke hoan vi";
			break;
	}
}

