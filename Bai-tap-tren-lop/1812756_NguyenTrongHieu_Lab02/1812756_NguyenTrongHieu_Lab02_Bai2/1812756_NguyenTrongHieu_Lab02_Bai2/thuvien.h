#pragma once
#define MAX 100

struct Date
{
	unsigned int ngay;
	unsigned int thang;
	unsigned int nam;
};

struct Name
{
	char ho[11];
	char tLot[11];
	char ten[11];
};

struct NhanVien
{
	char maNV[8];
	Name name;
	Date date;
	char diaChi[16];
	unsigned int luong;
};


int DocDanhSachNhanVien(char* filename, NhanVien a[], int& n);
void Xuat_DS_NV(NhanVien a[], int n);


int DocDanhSachNhanVien(char *filename, NhanVien a[], int &n)
{
	ifstream input(filename);

	if (!input)
	{
		cout << "\nLoi doc file!" << endl;
		return 0;
	}

	int i = 0;
	while (!input.eof())
	{
		input >> a[i].maNV;
		input >> a[i].name.ho;
		input >> a[i].name.tLot;
		input >> a[i].name.ten;
		input >> a[i].date.ngay;
		input >> a[i].date.thang;
		input >> a[i].date.nam;
		input >> a[i].diaChi;
		input >> a[i].luong;
		i++;
	}

	n = i;
	input.close();
}

void XuatDuongKe(char kitu)
{
	const int chieuDai = 89;
	cout << '|';
	for (int i = 0; i < chieuDai; i++)
		cout << kitu;
	cout << '|' << endl;
}

void XuatTieuDe()
{
	XuatDuongKe('=');
	cout << setiosflags(ios::left)
		<< '|' << setw(10)  << "Ma NV"
		<< '|' << setw(11) << "Ho"
		<< setw(11) << "tLot"
		<< setw(11) << "Ten"
		<< '|' << setw(13) << "NTN Sinh"
		<< '|' << setw(16) << "Dia chi"
		<< '|' << setw(13) << "Luong";
	cout << '|' << endl;
	XuatDuongKe('=');
}

void Xuat_1_NV(NhanVien nv)
{
	cout << setiosflags(ios::left)
		<< '|' << setw(10) << nv.maNV
		<< '|' << setw(11) << nv.name.ho
		<< setw(11) << nv.name.tLot
		<< setw(11) << nv.name.ten
		<< '|' << setw(2) << nv.date.ngay
		<< '/' << setw(2) << nv.date.thang
		<< '/' << setw(7) << nv.date.nam
		<< '|' << setw(16) << nv.diaChi
		<< '|' << setw(13) << nv.luong;
	cout << '|' << endl;
}

void Xuat_DS_NV(NhanVien a[], int n)
{
	XuatTieuDe();

	for (int i = 0; i < n; i++)
	{
		Xuat_1_NV(a[i]);
		if ((i + 1) % 3 == 0)
			XuatDuongKe('-');
	}

	XuatDuongKe('=');
}

