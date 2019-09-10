#pragma once
#define MAX 100

int DocMang(int a[], int& n, char* filename);
void XuatMang(int a[], int n);
void ChonTrucTiep(int a[], int n);
void chenTrucTiep(int arr[], int n);
void DoiChoTrucTiep(int a[], int n);
void bubbleSort(int a[], int n);
void saoChepMang(int des[], int src[], int n);

void saoChepMang(int des[], int src[], int n)
{
	for (int i = 0; i < n; i++)
		des[i] = src[i];
}

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
	int tempArr[MAX];
	saoChepMang(tempArr, a, n);

	for (int i = 0; i < n - 1; i++)
	{
		int vt_min = Min_A_B(i, n - 1, tempArr, n);
		HoanVi(tempArr[i], tempArr[vt_min]);
	}

	cout << "\nMang sau khi sap xep tang dan:\n";
	XuatMang(tempArr, n);
}

void chenTrucTiep(int arr[], int n)
{
	int tempArr[MAX];
	saoChepMang(tempArr, arr, n);

	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = tempArr[i];
		j = i - 1;

		while (j >= 0 && tempArr[j] > key)
		{
			tempArr[j + 1] = tempArr[j];
			j = j - 1;
		}
		tempArr[j + 1] = key;
	}

	cout << "\nMang sau khi sap xep tang dan:\n";
	XuatMang(tempArr, n);
}

void DoiChoTrucTiep(int a[], int n)
{
	int tempArr[MAX];
	saoChepMang(tempArr, a, n);

	for (int i = 0; i < n - 1; i++)
	for (int j = i + 1; j < n; j++)
	if (tempArr[i] > tempArr[j])
		HoanVi(tempArr[i], tempArr[j]);

	cout << "\nMang sau khi sap xep tang dan:\n";
	XuatMang(tempArr, n);
}

void bubbleSort(int a[], int n)
{
	int tempArr[MAX];
	saoChepMang(tempArr, a, n);

	for (int i = 0; i < n - 1; i++)
	for (int j = n - 1; j > i; j--)
	if (tempArr[j] < tempArr[j - 1])
		HoanVi(tempArr[j], tempArr[j - 1]);

	cout << "\nMang sau khi sap xep tang dan:\n";
	XuatMang(tempArr, n);
}
