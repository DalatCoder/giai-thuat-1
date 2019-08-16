#include <iostream>
#include <iomanip>

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
	int menu, soMenu = 5;
	int n = 0;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, n);
		system("PAUSE");
	} while (menu > 0);
	system("PAUSE");
}
