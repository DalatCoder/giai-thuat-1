#define MAX 100

/*
* Nguyen mau ham
*/
// Tong Quat
void NhapDay(int a[MAX], int &n);
void XuatDay(int a[MAX], int n);

// Chuc nang 1
void MinMax(int a[MAX], int l, int r, int &min, int &max);

// Chuc nang 2
void NhapChiSo_Trai_Phai(int &l, int &r, int n);
void HoanVi(int &a, int &b);
void HoanViChuoi(int a[MAX], int i, int j, int m);
void ChuyenChuoi(int a[MAX], int n, int m);

// Chuc nang 3
void LietKe_NP(int i, int a[MAX], int n);

// Chuc nang 4


/*
 * Dinh nghia ham
 */
void NhapDay(int a[MAX], int &n)
{
	do
	{
		cout << "\nNhap so phan tu cua mang: ";
		cin >> n;
	} while (n <= 0 || n >= MAX);

	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = -9 + rand() % 18;
}

void XuatDay(int a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
	cout << endl;
}

void MinMax(int a[MAX], int l, int r, int &min, int &max)
{
	if (l == r)
	{
		min = a[l];
		max = a[l];
	}
	else
	{
		int min1, max1, min2, max2;
		MinMax(a, l, (l + r) / 2, min1, max1);
		MinMax(a, (l + r) / 2 + 1, r, min2, max2);
		min = min1 < min2 ? min1 : min2;
		max = max1 > max2 ? max1 : max2;
	}
}

void NhapChiSo_Trai_Phai(int &l, int &r, int n)
{
	do
	{
		cout << "\nNhap chi so trai: (0 <= l <= r < " << n << ") ";
		cin >> l;
	} while (l < 0 || l >= n);

	do
	{
		cout << "\nNhap chi so phai: (0 <= " << l << " < r < " << n << ") ";
		cin >> r;
	} while (r < 0 || r < l || r >= n);
}

void HoanVi(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

void HoanViChuoi(int a[MAX], int i, int j, int m)
{
	for (int k = 0; k < m; k++)
		HoanVi(a[i + k], a[j + k]);
}

void ChuyenChuoi(int a[MAX], int n, int m)
{
	int i = m;
	int j = n - m;

	while (i != j)
	{
		if (i > j)
		{
			HoanViChuoi(a, m - i, m, j);
			i = i - j;
		}
		else
		{
			j = j - i;
			HoanViChuoi(a, m - i, m + j, i);
		}
	}

	HoanViChuoi(a, m-i, m, i);
}

void LietKe_NP(int i, int a[MAX], int n)
{
	for (int j = 0; j <= 1; j++)
	{
		a[i] = j;
		if (i < n - 1)
			LietKe_NP(i + 1, a, n);
		else
			XuatDay(a, n);
	}
}
