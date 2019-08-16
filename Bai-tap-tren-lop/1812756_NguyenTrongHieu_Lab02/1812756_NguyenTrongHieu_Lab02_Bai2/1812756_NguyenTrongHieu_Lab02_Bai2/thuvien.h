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
void TimKiem_NS(NhanVien a[], int n, unsigned int namSinh);
void TimKiem_NS_Luong(NhanVien a[], int n, unsigned int namSinh, unsigned int luong);
void TimKiem_HoTen(NhanVien a[], int n, Name name, unsigned int nam);
void TimKiem_Ten_DiaChi(NhanVien a[], int n, Name name, char diaChi[]);
int  TinhChieuDaiChuoi(char a[]);

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

void TimKiem_NS(NhanVien a[], int n, unsigned int namSinh)
{
	int m = 0;
	NhanVien b[MAX];

	for (int i = 0; i < n; i++)
		if (a[i].date.nam == namSinh)
		{
			b[m] = a[i];
			m++;
		}

	if (m == 0)
		cout << "\nKhong tim thay nhan vien co nam sinh: " << namSinh << endl;
	else
	{
		cout << "\nDa tim thay " << m << " nhan vien co nam sinh: " << namSinh << endl;
		
		// Xuat danh sach nhan vien tim thay
		XuatTieuDe();
		for (int i = 0; i < m; i++)
		{
			Xuat_1_NV(b[i]);
			if ((i + 1) % 3 == 0)
				XuatDuongKe('-');
		}
		XuatDuongKe('=');
	}
}

void TimKiem_NS_Luong(NhanVien a[], int n, unsigned int namSinh, unsigned int luong)
{
	int m = 0;
	NhanVien b[MAX];

	for (int i = 0; i < n; i++)
		if (a[i].date.nam <= namSinh && a[i].luong >= luong)
		{
			b[m] = a[i];
			m++;
		}

	if (m == 0)
		cout << "\nKhong tim thay nhan vien co nam sinh <= " << namSinh << " va co muc luong >= " << luong  << endl;
	else
	{
		cout << "\nDa tim thay " << m << " nhan vien co nam sinh <= " << namSinh << " va co muc luong >= " << luong << endl;

		// Xuat danh sach nhan vien tim thay
		XuatTieuDe();
		for (int i = 0; i < m; i++)
		{
			Xuat_1_NV(b[i]);
			if ((i + 1) % 3 == 0)
				XuatDuongKe('-');
		}
		XuatDuongKe('=');
	}
}

void TimKiem_HoTen(NhanVien a[], int n, Name name, unsigned int namSinh)
{
	int m = 0;
	NhanVien b[MAX];

	for (int i = 0; i < n; i++)
		if (strcmp(a[i].name.ho, name.ho)==0 && strcmp(a[i].name.ten, name.ten)==0 && a[i].date.nam < namSinh)
		{
			b[m] = a[i];
			m++;
		}

	if (m == 0)
		cout << "\nKhong tim thay nhan vien co ho " << name.ho << " va co ten " << name.ten << endl;
	else
	{
		if (namSinh != 9999)
			cout << "\nDa tim thay " << m << " nhan vien co ho " << name.ho << " va co ten " << name.ten << " va co nam sinh < " << namSinh << endl;
		else
			cout << "\nDa tim thay " << m << " nhan vien co ho " << name.ho << " va co ten " << name.ten << endl;
		// Xuat danh sach nhan vien tim thay
		XuatTieuDe();
		for (int i = 0; i < m; i++)
		{
			Xuat_1_NV(b[i]);
			if ((i + 1) % 3 == 0)
				XuatDuongKe('-');
		}
		XuatDuongKe('=');
	}
}

int  TinhChieuDaiChuoi(char a[])
{
	int res = 0;

	while (a[res] != '\0')
		res++;

	return res;
}

void TimKiem_Ten_DiaChi(NhanVien a[], int n, Name name, char diaChi[])
{
	int m = 0;
	NhanVien b[MAX];

	for (int i = 0; i < n; i++)
		if (strcmp(a[i].name.ten, name.ten) == 0 && strcmp(a[i].diaChi, diaChi) == 0)
		{
			b[m] = a[i];
			m++;
		}

	if (m == 0)
		cout << "\nKhong tim thay nhan vien co ten " << name.ten << " va co dia chi " << diaChi << endl;
	else
	{
		cout << "\nDa tim thay " << m << " nhan vien co ten " << name.ten << " va co dia chi " << diaChi << endl;

		// Xuat danh sach nhan vien tim thay
		XuatTieuDe();
		for (int i = 0; i < m; i++)
		{
			Xuat_1_NV(b[i]);
			if ((i + 1) % 3 == 0)
				XuatDuongKe('-');
		}
		XuatDuongKe('=');
	}
}
