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
void Tang_MaNV(NhanVien a[], int n);
void Tang_DiaChi(NhanVien arr[], int n);
void Tang_Luong(NhanVien a[], int n);
void QuickSort(NhanVien a[MAX], int l, int r);

int DocDanhSachNhanVien(char* filename, NhanVien a[], int& n)
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
		<< '|' << setw(10) << "Ma NV"
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

// Tim vi tri cua maNV nho nhat tronng doan [begin...end]
int VT_Min(NhanVien a[], int begin, int end)
{
	int vt = begin;
	char min[8];
	strcpy_s(min, a[begin].maNV);

	for (int i = begin +1; i <= end; i++)
		if (strcmp(min, a[i].maNV) > 0)
		{
			strcpy_s(min, a[i].maNV);
			vt = i;
		}
	return vt;
}

// Hoan vi 2 nhan vien
void HoanVi(NhanVien &a, NhanVien &b)
{
	NhanVien t = a;
	a = b;
	b = t;
}

// Sap xep tang theo ma nhan vien, chon truc tiep
void Tang_MaNV(NhanVien a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int vt_min = VT_Min(a, i, n - 1);
		HoanVi(a[i], a[vt_min]);
	}
}

// Sap xep tang theo dia chi, chen truc tiep
void Tang_DiaChi(NhanVien arr[], int n)
{
	int i, j;
	char key[16];

	for (i = 1; i < n; i++)
	{
		// key = arr[i];
		strcpy_s(key, arr[i].diaChi);
		j = i - 1;

		while (j >= 0 && (strcmp(arr[j].diaChi, key) > 0)) //arr[j] > key
		{
			// arr[j + 1] = arr[j];
			strcpy_s(arr[j + 1].diaChi, arr[j].diaChi);
			j = j - 1;
		}
		// arr[j + 1] = key;
		strcpy_s(arr[j + 1].diaChi, key);
	}
}

// Sap xep tang dan theo tien luong, doi cho truc tiep
void Tang_Luong(NhanVien a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].luong > a[j].luong)
				HoanVi(a[i], a[j]);
}

void QuickSort(NhanVien a[MAX], int l, int r)
{
	int i, j;
	NhanVien x;
	x = a[(l + r) / 2];
	i = l; j = r;
	do
	{
		while (a[i].date.nam < x.date.nam)
			i++;
		while (a[j].date.nam > x.date.nam)
			j--;
		if (i <= j)
		{
			HoanVi(a[i], a[j]);
			i++; j--;
		}
	} while (i <= j);
	if (l < j)
		QuickSort(a, l, j);
	if (i < r)
		QuickSort(a, i, r);
}