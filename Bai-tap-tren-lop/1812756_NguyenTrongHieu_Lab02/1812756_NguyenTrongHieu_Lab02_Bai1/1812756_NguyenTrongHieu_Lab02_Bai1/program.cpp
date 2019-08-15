#include <iostream>
#include <fstream>

using namespace std;

#include "thuvien.h";
#include "menu.h";

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 0;
}

void ChayChuongTrinh()
{
	int a[MAX], n = 0;
	int menu, soMenu = 6;

	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(a, n, menu);
	} while (menu > 0);

	system("PAUSE");
}
