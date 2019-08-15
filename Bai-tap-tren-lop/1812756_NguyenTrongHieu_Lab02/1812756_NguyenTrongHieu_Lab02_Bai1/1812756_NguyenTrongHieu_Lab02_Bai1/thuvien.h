#define MAX 100

void docTapTin(char *filename, int a[MAX], int &n);
void XuatMang(int a[MAX], int n);
int TimKiem_TT(int a[MAX], int n, int x);
int TimKiem_TT_LC(int a[MAX], int n, int x);
int TimKiemNhiPhan(int a[MAX], int n, int x);

void docTapTin(char *filename, int a[MAX], int &n)
{
	ifstream input(filename);

	if (!input)
	{
		cout << "\nLoi doc tap tin.";
		exit(1);
	}

	input >> n;
	for (int i = 0; i < n; i++)
		input >> a[i];
}

void XuatMang(int a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
	cout << endl;
}

int TimKiem_TT(int a[MAX], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
		return -1; // Khong tim thay phan tu x trong mang a
	return i;
}

int TimKiem_TT_LC(int a[MAX], int n, int x)
{
	a[n] = x;
	int i = 0;

	while (a[i] != x)
		i++;

	if (i == n)
		return -1;
	return i;
}

void HoanVi(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void SapXepMang(int a[MAX], int n)
{
	for (int i = 0; i < n - 1; i++)
	for (int j = i + 1; j < n; j++)
	if (a[i] > a[j])
		HoanVi(a[i], a[j]);
}

int TimKiemNhiPhan(int a[MAX], int n, int x)
{
	int l = 0;
	int r = n - 1;
	int kq = -1; // khong tim thay phan tu x trong mang

	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (a[mid] == x)
		{
			kq = mid; // Tim thay phan tu trong mang
			break;
		}
		else
		{
			if (x < a[mid])
				r = mid - 1;
			else
				l = mid + 1;
		}
	}

	return kq; 
}

