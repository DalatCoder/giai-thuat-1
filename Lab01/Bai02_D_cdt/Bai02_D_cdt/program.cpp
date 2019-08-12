#include <iostream>

using namespace std;

#include "thuvien.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 0;
}

void ChayChuongTrinh()
{
	int a[MAX], n;
	int m;

	cout << "\nNhap n : "; 
	cin >> n;

	NhapDay(a, n);
	cout << "\nNhap m : ";
	cin >> m;

	cout << "\nDay ban dau: \n";
	XuatDay(a, n);

	Transpose(a, n, m);
	cout << "\nDay ket qua: \n";
	XuatDay(a, n);

	cout << endl;
	system("pause");
}
