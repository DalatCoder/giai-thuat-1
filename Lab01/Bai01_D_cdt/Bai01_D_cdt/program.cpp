#include <iostream>
#include <cstdlib>
#include <ctime>

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
	int l, r;
	int min = 0, max = 0;

	cout << "\nNhap n = "; 
	cin >> n;

	NhapDay(a, n);
	cout << "\nLeft = "; 
	cin >> l;

	cout << "\nRight = ";
	cin >> r;

	MinMax(a, l, r, min, max);

	cout << "\nDay da cho: " << endl;
	XuatDay(a, n);

	cout << "Min a[" << l << "..." << r << "] = " << min << endl;
	cout << "Max a[" << l << "..." << r << "] = " << max << endl;

	system("PAUSE");
}

