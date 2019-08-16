#pragma once
#define MAX 20

int		n, k;
int		a[MAX], b[MAX];
int		dem = 0;


void XuatKetQua(int a[MAX], int n);
void LietKe_DayNP(int i);


void XuatKetQua(int a[MAX], int n)
{
	cout << "kq" << setw(3) << dem << " : ";
	for (int i = 1; i <= n; i++)
		cout << setw(2) << a[i];
	cout << endl;
}

void LietKe_DayNP(int i)
{
	for (int j = 0; j <= 1; j++)
	{
		a[i] = j;
		if (i < n) 
			LietKe_DayNP(i + 1);
		else
		{
			dem++;
			XuatKetQua(a, n);
		}
	}
}

