#include <iostream>
#include <fstream>

using namespace std;

#include "thuvien.h"
#include "menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 0;
}

void ChayChuongTrinh()
{
	int kq;
	char filename[MAX];

	Stack s;
	CreateEmptyStack(s);

	do
	{
		cout << "\nNhap ten tap tin de mo: ";
		cin >> filename;
		kq = GetDataFromFile(filename, s);

		if (kq == 0)
			cout << "\nKiem tra lai ten tap tin.\n";
	} while (kq != 1);

	cout << "\nStack hien tai:";
	DisplayStack(s);
	system("pause");

	int soMenu = 5, menu;

	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, s);
	} while (menu > 0);

	cout << endl;
	system("pause");
}

