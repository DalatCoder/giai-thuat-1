#pragma once
#define MAX 100

int DocMang(int a[], int& n, char* filename);
void XuatMang(int a[], int n);
void ChonTrucTiep(int a[], int n);
void chenTrucTiep(int arr[], int n);
void DoiChoTrucTiep(int a[], int n);
void bubbleSort(int a[], int n);

int DocMang(int a[], int& n, char* filename)
{
	ifstream input(filename);

	if (!input)
		return 0;

	input >> n;
	for (int i = 0; i < n; i++)
		input >> a[i];

	input.close();
	return 1;
}

void XuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
	cout << endl;
}

int Min_A_B(int batdau, int ketthuc, int a[MAX], int n)
{
	int kq = a[batdau];
	int vt = batdau;

	for (int i = batdau + 1; i <= ketthuc; i++)
		if (kq > a[i])
		{
			kq = a[i];
			vt = i;
		}

	return vt;
}

void HoanVi(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void ChonTrucTiep(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int vt_min = Min_A_B(i, n - 1, a, n);
		HoanVi(a[i], a[vt_min]);
	}
}

void chenTrucTiep(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void DoiChoTrucTiep(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				HoanVi(a[i], a[j]);
}

void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])
				HoanVi(a[j], a[j - 1]);
}
